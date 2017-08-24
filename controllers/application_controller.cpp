#include "application_controller.hpp"
#include "../helpers/sessions_helper.hpp"

MiddlewarePtr AssetsMiddleware::call(Request &req, std::shared_ptr<Response> &resp) {
    auto sm = std::make_shared<StaticMiddleware>("." + req.getAbsPath());
    return sm->call(req, resp);
}

ForceLoggedIn::ForceLoggedIn(const MiddlewarePtr &nextMiddleware) : SimpleMiddleware(nextMiddleware) {}

void ForceLoggedIn::process(Request &req, std::shared_ptr<Response> &resp) {
    if (SessionsHelper::currentUser(req) == nullptr) {
        resp->setStatusCode(StatusCode::HTTP_SEE_OTHER);
        resp->headers.put("Location", std::make_shared<HeaderContent>("/login"));
        this->nextMiddleware = nullptr;
    }
}

ForceLoggedOut::ForceLoggedOut(const MiddlewarePtr &nextMiddleware) : SimpleMiddleware(nextMiddleware) {}

void ForceLoggedOut::process(Request &req, std::shared_ptr<Response> &resp) {
    if (SessionsHelper::currentUser(req) != nullptr) {
        resp->setStatusCode(StatusCode::HTTP_SEE_OTHER);
        resp->headers.put("Location", std::make_shared<HeaderContent>("/"));
        this->nextMiddleware = nullptr;
    }
}
