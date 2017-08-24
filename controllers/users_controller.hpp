#ifndef MSGBOARD_USERS_CONTROLLER_HPP
#define MSGBOARD_USERS_CONTROLLER_HPP

#include <hane/hane.hpp>

class NewUser : public Middleware {
    MiddlewarePtr call(RequestPtr req, std::shared_ptr<Response> &resp) override;
};

class CreateUser : public Middleware {
    MiddlewarePtr call(RequestPtr req, std::shared_ptr<Response> &resp) override;
};

class ShowUser : public Middleware {
    MiddlewarePtr call(RequestPtr req, std::shared_ptr<Response> &resp) override;
};

#endif