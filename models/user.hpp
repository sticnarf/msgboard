#ifndef MSGBOARD_USER_HPP
#define MSGBOARD_USER_HPP

#include <string>
#include <chrono>
#include <memory>

class User;

typedef std::shared_ptr<User> UserPtr;

class User {
private:
    int id;
    std::string username;
    std::string passwordSalt;
    std::string passwordDigest;
    std::chrono::system_clock::time_point createdAt;
public:
    int getId() const;

private:

    void setPassword(const std::string &password);

    void generateSalt();

    std::string generatePasswordDigest(const std::string &password);

public:
    const std::string &getUsername() const;

public:
    User() = default;

    User(const std::string &username, const std::string &password);

    bool authenticate(const std::string &password);

    bool save();

    static UserPtr getById(int id);

    static UserPtr getByUsername(const std::string &username);
};

#endif
