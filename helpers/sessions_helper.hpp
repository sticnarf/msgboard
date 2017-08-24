#ifndef MSGBOARD_SESSIONS_HELPER_HPP
#define MSGBOARD_SESSIONS_HELPER_HPP

#include <hane/hane.hpp>
#include "../models/user.hpp"

class SessionsHelper {
public:
    static UserPtr currentUser(RequestPtr req);

    static void loginUser(UserPtr user, RequestPtr req);

    static void logoutUser(RequestPtr req);
};

#endif
