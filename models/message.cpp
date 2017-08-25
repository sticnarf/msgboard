#include <hane/hane.hpp>
#include <sstream>
#include "../utils/date.h"
#include "message.hpp"
#include <iomanip>
#include <locale>
#include "../database/db_connection.hpp"

using namespace date;

int Message::getId() const {
    return id;
}

const std::string &Message::getContent() const {
    return content;
}

void Message::setContent(const std::string &content) {
    Message::content = content;
}

const std::chrono::system_clock::time_point &Message::getCreatedAt() const {
    return createdAt;
}

void Message::setCreatedAt(const std::chrono::system_clock::time_point &createdAt) {
    Message::createdAt = createdAt;
}

const UserPtr &Message::getAuthor() const {
    return author;
}

Message::Message(UserPtr author, const std::string &content) :
        author(author), content(content) {
    createdAt = std::chrono::system_clock::now();
}

bool Message::save() {
    auto &pool = DBPool::getInstance();
    DBConnection conn;

    try {
        pqxx::work txn(*conn);

        std::stringstream ss;
        ss << createdAt << " " << "UTC";

        txn.exec("INSERT INTO messages (user_id, content, created_at) VALUES ("
                 + txn.quote(author->getId()) + "," + txn.quote(content) + ","
                 + txn.quote(ss.str()) + ")");

        txn.commit();
        return true;
    } catch (const std::exception &e) {
        Logger::getInstance().error("Message::save error: {}", e.what());
        return false;
    }
}

std::vector<MessagePtr> Message::getAll() {
    auto &pool = DBPool::getInstance();
    DBConnection conn;

    try {
        pqxx::work txn(*conn);

        pqxx::result r = txn.exec(
                "SELECT messages.content, messages.created_at, users.username "
                        "FROM messages LEFT JOIN users ON messages.user_id = users.id "
                        "ORDER BY messages.created_at DESC LIMIT 10");

        auto num = r.size();
        std::vector<MessagePtr> v;

        for (int i = 0; i < num; i++) {
            auto author = std::make_shared<User>();
            author->setUsername(r[i][2].as<std::string>());
            std::string content = r[i][0].as<std::string>();
            std::string timeStr = r[i][1].as<std::string>();

            std::tm t = {};
            std::stringstream ss(timeStr);

            ss >> std::get_time(&t, "%Y-%m-%d %H:%M:%S");
            time_t tt = timegm(&t);

            auto message = std::make_shared<Message>(author, content, std::chrono::system_clock::from_time_t(tt));

            v.push_back(message);
        }

        return v;
    } catch (const std::exception &e) {
        Logger::getInstance().error("Message::save error: {}", e.what());
        return std::vector<MessagePtr>();
    }
}

Message::Message(UserPtr author, const std::string &content, std::chrono::system_clock::time_point createdAt) :
        author(author), content(content), createdAt(createdAt) {
}

std::string Message::getFriendlyCreatedAt() {
    std::time_t t = std::chrono::system_clock::to_time_t(createdAt);
    std::tm tm = *std::localtime(&t);
    std::stringstream ss;
    ss << std::put_time(&tm, "%c");
    return ss.str();
}
