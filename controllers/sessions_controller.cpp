#include "sessions_controller.hpp"
#include "../templates/sessions/new.html.hpp"

MiddlewarePtr NewSession::call(Request &req, std::shared_ptr<Response> &resp) {
    resp->body = SessionsNewHtml().render();

    return nullptr;
}

MiddlewarePtr DeleteSession::call(Request &req, std::shared_ptr<Response> &resp) {
    return nullptr;
}

MiddlewarePtr CreateSession::call(Request &req, std::shared_ptr<Response> &resp) {
    return nullptr;
}
