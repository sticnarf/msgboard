#include "sessions_controller.hpp"
#include "../templates/sessions/new.html.hpp"
#include "../helpers/sessions_helper.hpp"

MiddlewarePtr NewSession::call(RequestPtr req, std::shared_ptr<Response> &resp) {
    resp->body = SessionsNewHtml().render();

    return nullptr;
}

MiddlewarePtr DeleteSession::call(RequestPtr req, std::shared_ptr<Response> &resp) {
    SessionsHelper::logoutUser(req);
    resp->setStatusCode(StatusCode::HTTP_SEE_OTHER);
    resp->headers.put("Location", std::make_shared<HeaderContent>("/"));
    return nullptr;
}

MiddlewarePtr CreateSession::call(RequestPtr req, std::shared_ptr<Response> &resp) {
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
            resp->setStatusCode(StatusCode::HTTP_SEE_OTHER);
            resp->headers.put("Location", std::make_shared<HeaderContent>("/"));
        } else {
            errorMessages.emplace_back("Incorrect password!");
        }
    }

    if (!errorMessages.empty()) {
        resp->body = SessionsNewHtml(errorMessages).render();
    }

    return nullptr;
}
