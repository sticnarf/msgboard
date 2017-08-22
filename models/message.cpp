#include <hane/hane.hpp>
#include <sstream>
#include "../utils/date.h"
#include "message.hpp"
#include "../database/db_pool.hpp"

int Message::getId() const {
    return id;
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

const UserPtr &Message::getAuthor() const {
    return author;
}

Message::Message(UserPtr author, const std::string &content) :
        author(author), content(content) {
    createdAt = std::chrono::system_clock::now();
}

bool Message::save() {
    auto &pool = DBPool::getInstance();
    auto conn = pool.borrowConnection();

    try {
        pqxx::work txn(*conn);

        using namespace date;
        std::stringstream ss;
        ss << createdAt << " " << "UTC";

        txn.exec("INSERT INTO messages (user_id, content, created_at) VALUES ("
                 + txn.quote(author->getId()) + "," + txn.quote(content) + ","
                 + txn.quote(ss.str()) + ")");

        txn.commit();
        return true;
    } catch (const std::exception &e) {
        Logger::getInstance().error("Message::save error: {}", e.what());
        pool.returnConnection(conn);
        return false;
    }
}
