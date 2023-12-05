#include "TransactionSupport.cpp"
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

int main() {
    TransactionSupport db;
        db.get("A");
        db.put("A",5);
        db.begin_transaction();
        db.put("A", 5);
        cout << db.get("A") << endl;
        db.put("A", 6);
        db.commit();
        cout << db.get("A") << endl;
        db.commit();
        db.rollback();
        db.get("B");
        db.begin_transaction();
        db.put("B", 10);
        db.rollback();
        db.get("B");
}
