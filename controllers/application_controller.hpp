#ifndef MSGBOARD_APPLICATION_CONTROLLER_HPP
#define MSGBOARD_APPLICATION_CONTROLLER_HPP

#include <hane/hane.hpp>

class ForceLoggedIn : public SimpleMiddleware {
public:
    ForceLoggedIn(const MiddlewarePtr &nextMiddleware);

    MiddlewarePtr call(Request &req, std::shared_ptr<Response> &resp) override;
};

class ForceLoggedOut : public SimpleMiddleware {
public:
    ForceLoggedOut(const MiddlewarePtr &nextMiddleware);

    MiddlewarePtr call(Request &req, std::shared_ptr<Response> &resp) override;
};

class AssetsMiddleware : public Middleware {
public:
    MiddlewarePtr call(Request &req, std::shared_ptr<Response> &resp) override;
};

#endif
