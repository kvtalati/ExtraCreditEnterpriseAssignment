#include <map>
#include <string>
#include <iostream>
using namespace std;

class TransactionSupport {
private:
    map<string, int> mainStorage;
    map<string, int> transactionStorage;
    bool isInTransaction;
public:
    TransactionSupport() : isInTransaction(false) {}
    void begin_transaction();
    void put(const string& key, int value);
    int get(const string& key);
    void commit();
    void rollback();
};