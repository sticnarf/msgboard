#include <iostream>
#include <hane/hane.hpp>
#include "controllers/application_controller.hpp"
#include "templates/messages/list.html.hpp"
#include "helpers/sessions_helper.hpp"
#include "templates/sessions/new.html.hpp"
#include "templates/users/new.html.hpp"
#include "templates/messages/new.html.hpp"

static void login(RequestPtr req, ResponsePtr resp);

static void reg(RequestPtr req, ResponsePtr resp);

static void post(RequestPtr req, ResponsePtr resp);

int main() {
    Logger::getInstance().setLogPath("/var/log/msgboard.log");

    auto route = std::make_shared<RouteMiddleware>();
    auto session = std::make_shared<SessionMiddleware>(route);

    (*route)("GET")("/assets/.+")([](RequestPtr req, std::shared_ptr<Response> &resp) {
        return std::make_shared<StaticMiddleware>("." + req->getAbsPath())->call(req, resp);
    });

    (*route)("GET")("/")([](RequestPtr req, ResponsePtr resp) {
        resp->body = MessagesListHtml(Message::getAll(), SessionsHelper::currentUser(req)).render();
    });

    (*route)("GET")("/login")(build<ForceLoggedOut>([](RequestPtr req, ResponsePtr resp) {
        resp->body = SessionsNewHtml().render();
    }));

    (*route)("POST")("/login")(build<ForceLoggedOut>(login));

    (*route)("GET")("/logout")
            (build<ForceLoggedIn>([](RequestPtr req, ResponsePtr resp) {
                SessionsHelper::logoutUser(req);
                resp->redirectTo("/");
            }));

    (*route)("GET")("/users/new")
            (build<ForceLoggedOut>([](RequestPtr req, ResponsePtr resp) {
                resp->body = UsersNewHtml().render();
            }));

    (*route)("POST")("/users")(build<ForceLoggedOut>(reg));

    (*route)("GET")("/messages/new")
            (build<ForceLoggedIn>([](RequestPtr req, ResponsePtr resp) {
                resp->body = MessagesNewHtml().render();
            }));

    (*route)("POST")("/messages")(build<ForceLoggedIn>(post));

    HttpServer server(session, "0.0.0.0", 8089);
    server.start();

    return 0;
}

void login(RequestPtr req, ResponsePtr resp) {
    auto queries = req->getQueries();
    auto usernameEntry = queries.find("username");
    auto passwordEntry = queries.find("password");
    if (usernameEntry == queries.end() || passwordEntry == queries.end())
        throw HttpError(StatusCode::HTTP_BAD_REQUEST, "Queries missing");

    std::vector<std::string> errorMessages;

    auto username = usernameEntry->second.getData();
    auto password = passwordEntry->second.getData();

    auto user = User::getByUsername(username);
    if (user == nullptr) {
        errorMessages.emplace_back("User does not exist!");
    } else {
        if (user->authenticate(password)) {
            SessionsHelper::loginUser(user, req);
            resp->redirectTo("/");
        } else {
            errorMessages.emplace_back("Incorrect password!");
        }
    }

    if (!errorMessages.empty()) {
        resp->body = SessionsNewHtml(errorMessages).render();
    }
}

void reg(RequestPtr req, ResponsePtr resp) {
    auto queries = req->getQueries();
    auto usernameEntry = queries.find("username");
    auto passwordEntry = queries.find("password");
    auto passwordConfirmationEntry = queries.find("password_confirmation");
    if (usernameEntry == queries.end() || passwordEntry == queries.end() || passwordConfirmationEntry == queries.end())
        throw HttpError(StatusCode::HTTP_BAD_REQUEST, "Queries missing");

    std::vector<std::string> errorMessages;

    auto username = usernameEntry->second.getData();
    auto password = passwordEntry->second.getData();
    auto passwordConfirmation = passwordConfirmationEntry->second.getData();

    auto user = User::getByUsername(username);
    if (user != nullptr)
        errorMessages.emplace_back("User exists!");

    if (password != passwordConfirmation)
        errorMessages.emplace_back("Password confirmation is not equal to the password!");

    if (username.length() == 0)
        errorMessages.emplace_back("Username must not be empty!");

    if (password.length() == 0)
        errorMessages.emplace_back("Password must not be empty!");

    if (errorMessages.empty()) {
        user = std::make_shared<User>(username, password);
        if (user->save()) {
            SessionsHelper::loginUser(user, req);
            resp->redirectTo("/");
        } else {
            errorMessages.emplace_back("Unknown error!");
        }
    }

    if (!errorMessages.empty())
        resp->body = UsersNewHtml(errorMessages).render();
}

void post(RequestPtr req, ResponsePtr resp) {
    auto queries = req->getQueries();
    auto contentEntry = queries.find("content");
    if (contentEntry == queries.end())
        throw HttpError(StatusCode::HTTP_BAD_REQUEST, "Queries missing");

    std::vector<std::string> errorMessages;

    auto content = contentEntry->second.getData();
    auto user = SessionsHelper::currentUser(req);
    if (content.length() == 0)
        errorMessages.emplace_back("Content must not be empty!");

    if (errorMessages.empty()) {
        auto message = std::make_shared<Message>(user, content);
        if (message->save())
            resp->redirectTo("/");
        else
            errorMessages.emplace_back("Unknown error!");
    }

    if (!errorMessages.empty())
        resp->body = MessagesNewHtml(errorMessages).render();
}