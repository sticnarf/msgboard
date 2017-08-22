#ifndef MSGBOARD_LIST_HTML_HPP
#define MSGBOARD_LIST_HTML_HPP

#include <hane/ecp/template.hpp>
#include <vector>
#include "../../models/message.hpp"
#include "../../models/user.hpp"

class MessagesListHtml : Template {
private:
    std::vector<Message> messages;
    UserPtr currentUser;

public:
    MessagesListHtml(const std::vector<Message> &messages, UserPtr currentUser) :
            messages(messages), currentUser(currentUser) {}

    std::string render() override;
};

#endif
