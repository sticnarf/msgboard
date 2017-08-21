#ifndef MSGBOARD_LIST_HTML_HPP
#define MSGBOARD_LIST_HTML_HPP

#include <hane/ecp/template.hpp>
#include <vector>
#include "../../models/message.hpp"

class MessagesListHtml : Template {
private:
    std::vector<Message> messages;

public:
    MessagesListHtml(const std::vector<Message> &messages) : messages(messages) {}

    std::string render() override;
};

#endif
