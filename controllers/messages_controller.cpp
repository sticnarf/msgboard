#include "messages_controller.hpp"
#include "../templates/messages/list.html.hpp"
#include "../helpers/sessions_helper.hpp"
#include "../templates/messages/new.html.hpp"

MiddlewarePtr NewMessage::call(RequestPtr req, std::shared_ptr<Response> &resp) {
    resp->body = MessagesNewHtml().render();
    return nullptr;
}

//MiddlewarePtr ShowMessage::call(RequestPtr req, std::shared_ptr<Response> &resp) {
//    return nullptr;
//}

MiddlewarePtr ListMessage::call(RequestPtr req, std::shared_ptr<Response> &resp) {
    resp->body = MessagesListHtml(Message::getAll(), SessionsHelper::currentUser(req)).render();
    return nullptr;
}

//MiddlewarePtr DeleteMessage::call(RequestPtr req, std::shared_ptr<Response> &resp) {
//    return nullptr;
//}

MiddlewarePtr CreateMessage::call(RequestPtr req, std::shared_ptr<Response> &resp) {
    auto queries = req->getQueries();

    auto contentEntry = queries.find("content");

    if (contentEntry == queries.end())
        throw HttpError(StatusCode::HTTP_BAD_REQUEST, "Queries missing");

    std::vector<std::string> errorMessages;

    auto content = contentEntry->second.getData();

    auto user = SessionsHelper::currentUser(req);

    if (content.length() == 0) {
        errorMessages.emplace_back("Content must not be empty!");
    }

    if (errorMessages.empty()) {
        auto message = std::make_shared<Message>(user, content);
        if (message->save()) {
            resp->setStatusCode(StatusCode::HTTP_SEE_OTHER);
            resp->headers.put("Location", std::make_shared<HeaderContent>("/"));
        } else {
            errorMessages.emplace_back("Unknown error!");
        }
    }

    if (!errorMessages.empty()) {
        resp->body = MessagesNewHtml(errorMessages).render();
    }

    return nullptr;
}
