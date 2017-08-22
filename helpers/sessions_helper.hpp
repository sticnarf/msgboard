#ifndef MSGBOARD_SESSIONS_HELPER_HPP
#define MSGBOARD_SESSIONS_HELPER_HPP

#include <hane/hane.hpp>
#include "../models/user.hpp"

class SessionsHelper {
public:
    static UserPtr currentUser(Request &req);

    static void loginUser(UserPtr user, Request &req);

    static void logoutUser(Request &req);
};

#endif
