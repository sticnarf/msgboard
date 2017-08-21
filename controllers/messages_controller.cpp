#include "messages_controller.hpp"
#include "../templates/messages/list.html.hpp"

MiddlewarePtr NewMessage::call(Request &req, std::shared_ptr<Response> &resp) {
    return nullptr;
}

MiddlewarePtr ShowMessage::call(Request &req, std::shared_ptr<Response> &resp) {
    return nullptr;
}

MiddlewarePtr ListMessage::call(Request &req, std::shared_ptr<Response> &resp) {
    resp->body = MessagesListHtml(std::vector<Message>()).render();
    return nullptr;
}

MiddlewarePtr DeleteMessage::call(Request &req, std::shared_ptr<Response> &resp) {
    return nullptr;
}

MiddlewarePtr CreateMessage::call(Request &req, std::shared_ptr<Response> &resp) {
    return nullptr;
}
