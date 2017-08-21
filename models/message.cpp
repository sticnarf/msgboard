#include "message.hpp"

Message::Message(int id, int authorId,
                 const std::string &content,
                 const std::chrono::system_clock::time_point &createdAt) : id(id),
                                                                           authorId(authorId),
                                                                           content(content),
                                                                           createdAt(createdAt) {}

int Message::getId() const {
    return id;
}

void Message::setId(int id) {
    Message::id = id;
}

int Message::getAuthorId() const {
    return authorId;
}

void Message::setAuthorId(int authorId) {
    Message::authorId = authorId;
}

const std::string &Message::getContent() const {
    return content;
}

void Message::setContent(const std::string &content) {
    Message::content = content;
}

const std::chrono::system_clock::time_point &Message::getCreatedAt() const {
    return createdAt;
}

void Message::setCreatedAt(const std::chrono::system_clock::time_point &createdAt) {
    Message::createdAt = createdAt;
}
