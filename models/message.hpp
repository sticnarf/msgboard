#ifndef MSGBOARD_MESSAGE_HPP
#define MSGBOARD_MESSAGE_HPP

#include <string>
#include <chrono>
#include <memory>
#include "user.hpp"

class Message;

typedef std::shared_ptr<Message> MessagePtr;

class Message {
private:
    int id;
    UserPtr author;
    std::string content;
    std::chrono::system_clock::time_point createdAt;

public:
    Message() = default;

    Message(UserPtr author, const std::string &content);

    int getId() const;

    const UserPtr &getAuthor() const;

    const std::string &getContent() const;

    void setContent(const std::string &content);

    const std::chrono::system_clock::time_point &getCreatedAt() const;

    void setCreatedAt(const std::chrono::system_clock::time_point &createdAt);

    bool save();
};

#endif
