#include "users_controller.hpp"
#include "../templates/users/new.html.hpp"

MiddlewarePtr NewUser::call(Request &req, std::shared_ptr<Response> &resp) {
    resp->body = UsersNewHtml().render();
    return nullptr;
}

MiddlewarePtr CreateUser::call(Request &req, std::shared_ptr<Response> &resp) {
    return nullptr;
}

MiddlewarePtr ShowUser::call(Request &req, std::shared_ptr<Response> &resp) {
    return nullptr;
}
