#include "sessions_helper.hpp"

UserPtr SessionsHelper::currentUser(Request &req) {
    auto session = req.getSession();
    auto entry = session->find("current_user");
    if (entry == session->end())
        return nullptr;
    return std::static_pointer_cast<User>(entry->second);
}

void SessionsHelper::loginUser(UserPtr user, Request &req) {
    auto session = req.getSession();
    session->insert({"current_user", user});
}

void SessionsHelper::logoutUser(Request &req) {
    auto session = req.getSession();
    auto entry = session->find("current_user");
    if (entry != session->end())
        session->erase(entry);
}


