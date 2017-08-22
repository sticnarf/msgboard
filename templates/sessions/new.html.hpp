#ifndef MSGBOARD_SESSIONS_NEW_HTML_HPP
#define MSGBOARD_SESSIONS_NEW_HTML_HPP

#include <hane/hane.hpp>
#include <vector>

class SessionsNewHtml : Template {
    std::vector<std::string> errorMessages;

public:
    SessionsNewHtml() = default;

    SessionsNewHtml(const std::vector<std::string> &errorMessages) : errorMessages(errorMessages) {}

    std::string render() override;
};

#endif
