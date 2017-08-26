#ifndef MSGBOARD_APPLICATION_CONTROLLER_HPP
#define MSGBOARD_APPLICATION_CONTROLLER_HPP

#include <hane/hane.hpp>

class ForceLoggedIn : public SimpleMiddleware {
public:
    ForceLoggedIn(MiddlewarePtr nextMiddleware);

    MiddlewarePtr call(RequestPtr req, std::shared_ptr<Response> &resp) override;
};

class ForceLoggedOut : public SimpleMiddleware {
public:
    ForceLoggedOut(MiddlewarePtr nextMiddleware);

    MiddlewarePtr call(RequestPtr req, std::shared_ptr<Response> &resp) override;
};

template <typename T, typename F>
std::shared_ptr<T> build(F function) {
    return std::make_shared<T>(std::make_shared<LambdaMiddleware>(function));
}

class AssetsMiddleware : public Middleware {
public:
    MiddlewarePtr call(RequestPtr req, std::shared_ptr<Response> &resp) override;
};

#endif
