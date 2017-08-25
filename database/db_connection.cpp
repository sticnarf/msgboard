#include "db_connection.hpp"

DBConnection::~DBConnection() {
    DBPool::getInstance().returnConnection(conn);
}

DBConnection::DBConnection() {
    conn = DBPool::getInstance().borrowConnection();
}

pqxx::connection *DBConnection::getConn() const {
    return conn;
}

pqxx::connection &DBConnection::operator*() {
    return *conn;
}

pqxx::connection *DBConnection::operator->() {
    return conn;
}
