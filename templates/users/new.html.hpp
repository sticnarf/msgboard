#ifndef MSGBOARD_USER_NEW_HTML_HPP
#define MSGBOARD_USER_NEW_HTML_HPP

#include <hane/hane.hpp>
#include <vector>

class UsersNewHtml : Template {
    std::vector<std::string> errorMessages;

public:
    UsersNewHtml() = default;

    UsersNewHtml(const std::vector<std::string> &errorMessages) : errorMessages(errorMessages) {}

    std::string render() override;
};

#endif
