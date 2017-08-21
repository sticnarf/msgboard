#include "user.hpp"

User::User(int id, const std::string &email,
           const std::string &nickname, const std::string &password)
        : id(id), email(email) {
    setPassword(password);
}

void User::setPassword(const std::string &password) {

}

bool User::authenticate(const std::string &password) {
    return false;
}
