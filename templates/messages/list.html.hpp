#ifndef MSGBOARD_MESSAGES_LIST_HTML_HPP
#define MSGBOARD_MESSAGES_LIST_HTML_HPP

#include <hane/hane.hpp>
#include <vector>
#include "../../helpers/application_helper.hpp"
#include "../../models/message.hpp"
#include "../../models/user.hpp"

class MessagesListHtml : Template {
private:
    std::vector<MessagePtr> messages;
    UserPtr currentUser;

public:
    MessagesListHtml(const std::vector<MessagePtr> &messages, UserPtr currentUser) :
            messages(messages), currentUser(currentUser) {}

    std::string render() override;
};

#endif
