#include "users_controller.hpp"
#include "../templates/users/new.html.hpp"
#include "../models/user.hpp"
#include "../helpers/sessions_helper.hpp"
#include <vector>

MiddlewarePtr NewUser::call(RequestPtr req, std::shared_ptr<Response> &resp) {
    resp->body = UsersNewHtml().render();
    return nullptr;
}

MiddlewarePtr CreateUser::call(RequestPtr req, std::shared_ptr<Response> &resp) {
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

    if (user != nullptr) {
        errorMessages.emplace_back("User exists!");
    }

    if (password != passwordConfirmation) {
        errorMessages.emplace_back("Password confirmation is not equal to the password!");
    }

    if (username.length() == 0) {
        errorMessages.emplace_back("Username must not be empty!");
    }

    if (password.length() == 0) {
        errorMessages.emplace_back("Password must not be empty!");
    }

    if (errorMessages.empty()) {
        user = std::make_shared<User>(username, password);
        if (user->save()) {
            SessionsHelper::loginUser(user, req);
            resp->setStatusCode(StatusCode::HTTP_SEE_OTHER);
            resp->headers.put("Location", std::make_shared<HeaderContent>("/"));
        } else {
            errorMessages.emplace_back("Unknown error!");
        }
    }

    if (!errorMessages.empty()) {
        resp->body = UsersNewHtml(errorMessages).render();
    }

    return nullptr;
}

MiddlewarePtr ShowUser::call(RequestPtr req, std::shared_ptr<Response> &resp) {
    return nullptr;
}
