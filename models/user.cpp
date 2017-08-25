#include "user.hpp"
#include "../database/db_connection.hpp"
#include <random>
#include <pqxx/pqxx>
#include <cryptopp/filters.h>
#include <cryptopp/base64.h>
#include <cryptopp/sha.h>
#include <hane/hane.hpp>

User::User(const std::string &username, const std::string &password)
        : username(username) {
    setPassword(password);
}

void User::setPassword(const std::string &password) {
    generateSalt();
    passwordDigest = generatePasswordDigest(password);
}

bool User::authenticate(const std::string &password) {
    return passwordDigest == generatePasswordDigest(password);
}

void User::generateSalt() {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static const char alphanum[] = "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    static std::uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);

    const int len = 8;
    char result[len + 1];

    for (int i = 0; i < len; i++)
        result[i] = alphanum[dis(mt)];
    result[len] = '\0';

    passwordSalt = result;
}

std::string User::generatePasswordDigest(const std::string &password) {
    CryptoPP::SHA256 hash;
    std::string digest;
    CryptoPP::StringSource ss
            (password + passwordSalt, true,
             new CryptoPP::HashFilter(hash,
                                      new CryptoPP::Base64Encoder(new CryptoPP::StringSink(digest))));

    return digest;
}

UserPtr User::getById(int id) {
    DBConnection conn;

    try {
        pqxx::work txn(*conn);
        pqxx::result r = txn.exec("SELECT username, password_digest, salt FROM users WHERE id=" + txn.quote(id));

        if (r.size() == 0)
            return nullptr;

        auto res = std::make_shared<User>();
        res->id = id;
        res->username = r[0][0].as<std::string>();
        res->passwordDigest = r[0][1].as<std::string>();
        res->passwordSalt = r[0][2].as<std::string>();
        return res;
    } catch (const std::exception &e) {
        Logger::getInstance().error("User::getById error: {}", e.what());
        return nullptr;
    }
}

UserPtr User::getByUsername(const std::string &username) {
    DBConnection conn;

    try {
        pqxx::work txn(*conn);
        pqxx::result r = txn.exec("SELECT id, password_digest, salt "
                                          "FROM users WHERE username=" + txn.quote(username));

        if (r.size() == 0)
            return nullptr;

        auto res = std::make_shared<User>();
        res->id = r[0][0].as<int>();
        res->username = username;
        res->passwordDigest = r[0][1].as<std::string>();
        res->passwordSalt = r[0][2].as<std::string>();
        return res;
    } catch (const std::exception &e) {
        Logger::getInstance().error("User::getByUsername error: {}", e.what());
        return nullptr;
    }
}

bool User::save() {
    DBConnection conn;

    try {
        pqxx::work txn(*conn);

        txn.exec("INSERT INTO users (username, password_digest, salt) VALUES ("
                 + txn.quote(username) + "," + txn.quote(passwordDigest) + ","
                 + txn.quote(passwordSalt) + ")");

        txn.commit();

        auto newUser = getByUsername(username);
        this->id = newUser->id;
        return true;
    } catch (const std::exception &e) {
        Logger::getInstance().error("User::save error: {}", e.what());
        return false;
    }
}

const std::string &User::getUsername() const {
    return username;
}

int User::getId() const {
    return id;
}

void User::setUsername(const std::string &username) {
    User::username = username;
}