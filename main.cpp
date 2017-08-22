#include <iostream>
#include <hane/hane.hpp>
#include "controllers/sessions_controller.hpp"
#include "controllers/messages_controller.hpp"
#include "controllers/users_controller.hpp"

class AssetsMiddleware : public Middleware {
public:
    MiddlewarePtr call(Request &req, std::shared_ptr<Response> &resp) override {
        auto sm = std::make_shared<StaticMiddleware>("." + req.getAbsPath());
        return sm->call(req, resp);
    }
};

int main() {
    Logger::getInstance().setLogPath("/var/log/msgboard.log");

    auto route = std::make_shared<RouteMiddleware>();

    // Add assets
    auto assets = std::make_shared<AssetsMiddleware>();
    route->addRule(std::regex("/assets/.+"), HttpMethod::METHOD_GET, assets);

    route->addRule(std::regex("/"), HttpMethod::METHOD_GET, std::make_shared<ListMessage>());

    route->addRule(std::regex("/login"), HttpMethod::METHOD_GET, std::make_shared<NewSession>());
    route->addRule(std::regex("/login"), HttpMethod::METHOD_POST, std::make_shared<CreateSession>());
    route->addRule(std::regex("/logout"), HttpMethod::METHOD_GET, std::make_shared<DeleteSession>());

    route->addRule(std::regex("\\/users\\/new"), HttpMethod::METHOD_GET, std::make_shared<NewUser>());
    route->addRule(std::regex("\\/users\\/{0,1}"), HttpMethod::METHOD_POST, std::make_shared<CreateUser>());

    auto session = std::make_shared<SessionMiddleware>(route);

    HttpServer server(session, "0.0.0.0", 8089);
    server.start();

    return 0;
}