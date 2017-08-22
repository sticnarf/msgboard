#ifndef MSGBOARD_LIST_HTML_HPP
#define MSGBOARD_LIST_HTML_HPP

#include <hane/ecp/template.hpp>
#include <vector>

class SessionsNewHtml : Template {
    std::vector<std::string> errorMessages;

public:
    SessionsNewHtml() = default;

    SessionsNewHtml(const std::vector<std::string> &errorMessages) : errorMessages(errorMessages) {}

    std::string render() override;
};

#endif
