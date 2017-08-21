#ifndef MSGBOARD_MESSAGES_CONTROLLER_HPP
#define MSGBOARD_MESSAGES_CONTROLLER_HPP

#include <hane/hane.hpp>

class NewMessage : public Middleware {
    MiddlewarePtr call(Request &req, std::shared_ptr<Response> &resp) override;
};

class CreateMessage : public Middleware {
    MiddlewarePtr call(Request &req, std::shared_ptr<Response> &resp) override;
};

class ShowMessage : public Middleware {
    MiddlewarePtr call(Request &req, std::shared_ptr<Response> &resp) override;
};

class ListMessage : public Middleware {
    MiddlewarePtr call(Request &req, std::shared_ptr<Response> &resp) override;
};

class DeleteMessage : public Middleware {
    MiddlewarePtr call(Request &req, std::shared_ptr<Response> &resp) override;
};

#endif
