#ifndef MSGBOARD_MESSAGES_NEW_HTML_HPP
#define MSGBOARD_MESSAGES_NEW_HTML_HPP

#include <hane/hane.hpp>

class MessagesNewHtml : Template {
    std::vector<std::string> errorMessages;

public:
    MessagesNewHtml() = default;

    MessagesNewHtml(const std::vector<std::string> &errorMessages) : errorMessages(errorMessages) {}

    std::string render() override;
};

#endif
