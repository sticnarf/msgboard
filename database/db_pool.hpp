#ifndef MSGBOARD_DB_POOL_HPP
#define MSGBOARD_DB_POOL_HPP

#include <vector>
#include <pqxx/pqxx>
#include <mutex>
#include <condition_variable>

class DBPool {
    std::vector<pqxx::connection *> freeConnections;

    std::mutex poolMutex;
    std::mutex returnMutex;

    std::condition_variable returnCv;

    static const int DEFAULT_POOL_SIZE = 8;

    explicit DBPool(int poolSize = DEFAULT_POOL_SIZE);

    // DBPool singleton lives the whole program lifetime, so the destructor is omitted.

public:
    static DBPool &getInstance();

    pqxx::connection *borrowConnection();

    // Not C++ way, however
    void returnConnection(pqxx::connection *conn);
};

#endif
