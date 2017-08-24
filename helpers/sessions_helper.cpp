#include "sessions_helper.hpp"

UserPtr SessionsHelper::currentUser(RequestPtr req) {
    auto session = req->getSession();
    auto entry = session->find("current_user");
    if (entry == session->end())
        return nullptr;
    return std::static_pointer_cast<User>(entry->second);
}

void SessionsHelper::loginUser(UserPtr user, RequestPtr req) {
    auto session = req->getSession();
    session->insert({"current_user", user});
    Logger::getInstance().info("{} logged in!", user->getUsername());
}

void SessionsHelper::logoutUser(RequestPtr req) {
    auto session = req->getSession();
    auto entry = session->find("current_user");
    if (entry != session->end()) {
        Logger::getInstance().info("{} logged out!", std::static_pointer_cast<User>(entry->second)->getUsername());
        session->erase(entry);
    }
}


