#ifndef MSGBOARD_USER_HPP
#define MSGBOARD_USER_HPP

#include <string>
#include <chrono>

class User {
private:
    int id;
    std::string email;
    std::string nickname;
    std::string passwordSalt;
    std::string passwordDigit;
    std::chrono::system_clock::time_point createdAt;

    void setPassword(const std::string &password);

public:
    User(int id, const std::string &email, const std::string &nickname, const std::string &password);

    bool authenticate(const std::string &password);
};

#endif
