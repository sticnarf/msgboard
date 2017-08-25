#include "db_pool.hpp"
#include <cstdlib>

DBPool &DBPool::getInstance() {
    static DBPool dbPool;
    return dbPool;
}

DBPool::DBPool(int poolSize) {
    char *connStr = std::getenv("PQ_CONN");

    for (int i = 0; i < poolSize; i++) {
        freeConnections.push(new pqxx::connection(connStr));
    }
}

pqxx::connection *DBPool::borrowConnection() {
    std::unique_lock<std::mutex> lock(returnMutex);
    returnCv.wait(lock, [&] { return !freeConnections.empty(); });

    std::lock_guard<std::mutex> poolLock(poolMutex);
    auto conn = freeConnections.front();
    freeConnections.pop();
    return conn;
}

void DBPool::returnConnection(pqxx::connection *conn) {
    std::lock_guard<std::mutex> poolLock(poolMutex);
    {
        std::lock_guard<std::mutex> lock(returnMutex);
        freeConnections.push(conn);
    }
    returnCv.notify_one();
}
