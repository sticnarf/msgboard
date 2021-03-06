#include "application_controller.hpp"
#include "../helpers/sessions_helper.hpp"

MiddlewarePtr AssetsMiddleware::call(RequestPtr req, std::shared_ptr<Response> &resp) {
    auto sm = std::make_shared<StaticMiddleware>("." + req->getAbsPath());
    return sm->call(req, resp);
}

MiddlewarePtr ForceLoggedIn::call(RequestPtr req, std::shared_ptr<Response> &resp) {
    if (SessionsHelper::currentUser(req) == nullptr) {
        resp->setStatusCode(StatusCode::HTTP_SEE_OTHER);
        resp->headers.put("Location", std::make_shared<HeaderContent>("/login"));
        return nullptr;
    }
    return nextMiddleware->call(req, resp);
}

ForceLoggedIn::ForceLoggedIn(MiddlewarePtr nextMiddleware) : SimpleMiddleware(nextMiddleware) {}

MiddlewarePtr ForceLoggedOut::call(RequestPtr req, std::shared_ptr<Response> &resp) {
    if (SessionsHelper::currentUser(req) != nullptr) {
        resp->setStatusCode(StatusCode::HTTP_SEE_OTHER);
        resp->headers.put("Location", std::make_shared<HeaderContent>("/"));
    }
    return nextMiddleware->call(req, resp);
}

ForceLoggedOut::ForceLoggedOut(MiddlewarePtr nextMiddleware) : SimpleMiddleware(nextMiddleware) {}
