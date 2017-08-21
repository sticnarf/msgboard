#ifndef MSGBOARD_MESSAGE_HPP
#define MSGBOARD_MESSAGE_HPP

#include <string>
#include <chrono>

class Message {
private:
    int id;
    int authorId;
    std::string content;
    std::chrono::system_clock::time_point createdAt;
public:
    Message(int id, int authorId, const std::string &content, const std::chrono::system_clock::time_point &createdAt);

    int getId() const;

    void setId(int id);

    int getAuthorId() const;

    void setAuthorId(int authorId);

    const std::string &getContent() const;

    void setContent(const std::string &content);

    const std::chrono::system_clock::time_point &getCreatedAt() const;

    void setCreatedAt(const std::chrono::system_clock::time_point &createdAt);
};

#endif
