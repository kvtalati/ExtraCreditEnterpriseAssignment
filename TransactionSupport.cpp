#include "header.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

void TransactionSupport::begin_transaction() {
    if (isInTransaction) {
        cout << "Transaction already in progress" << endl;
    }
    isInTransaction = true;
    transactionStorage.clear();
}

void TransactionSupport::put(const string& key, int value) {
    if (!isInTransaction) {
        cout << "No transaction in progress" << endl;
    }
    transactionStorage[key] = value;
}

int TransactionSupport::get(const string& key) {
    if (isInTransaction && transactionStorage.find(key) != transactionStorage.end()) {
        return transactionStorage[key];
    }
    if (mainStorage.find(key) != mainStorage.end()) {
        return mainStorage[key];
    }
    else {
        cout << "Key not found" << endl;
        return 0;
    }
}

void TransactionSupport::commit() {
    if (!isInTransaction) {
        cout << "No transaction to commit" << endl;
    }
    for (const auto& pair : transactionStorage) {
        mainStorage[pair.first] = pair.second;
    }
    isInTransaction = false;
    transactionStorage.clear();
}

void TransactionSupport::rollback() {
    if (!isInTransaction) {
        cout << "No transaction to rollback" << endl;
    }
    isInTransaction = false;
    transactionStorage.clear();
}
