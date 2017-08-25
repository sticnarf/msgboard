#ifndef MSGBOARD_DB_CONNECTION_HPP
#define MSGBOARD_DB_CONNECTION_HPP

#include <pqxx/connection>
#include "db_pool.hpp"

/**
 * DBConnection is an RAII wrapper for DBPool.
 * Make sure the DBConnection object is still in scope
 * when using the connection!
 */
class DBConnection {
private:
    pqxx::connection *conn;

public:
    DBConnection();

    ~DBConnection();

    pqxx::connection *getConn() const;

    pqxx::connection *operator->();

    pqxx::connection &operator*();
};

#endif
