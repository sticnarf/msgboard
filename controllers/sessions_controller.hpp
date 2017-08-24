#ifndef MSGBOARD_SESSION_CONTROLLER_HPP
#define MSGBOARD_SESSION_CONTROLLER_HPP
#include <hane/hane.hpp>

class NewSession : public Middleware {
    MiddlewarePtr call(RequestPtr req, std::shared_ptr<Response> &resp) override;
};

class CreateSession : public Middleware {
    MiddlewarePtr call(RequestPtr req, std::shared_ptr<Response> &resp) override;
};

class DeleteSession : public Middleware {
    MiddlewarePtr call(RequestPtr req, std::shared_ptr<Response> &resp) override;
};

#endif