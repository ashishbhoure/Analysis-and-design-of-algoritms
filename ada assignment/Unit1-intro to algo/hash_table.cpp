//Ques: Implement a hash table data structure using separate chaining collision resolution.

#include <iostream>
#include <list>

using namespace std;

// hash table class
class HashTable {
private:
    static const int capacity = 10; // capacity of the hash table
    list<pair<int, int>> table[capacity]; // array of linked lists to store key-value pairs

public:
    // hash function
    int hashFunction(int key) {
        return key % capacity;
    }

    // insert function
    void insert(int key, int value) {
        int index = hashFunction(key);
        table[index].push_back(make_pair(key, value));
    }

    // search function
    int search(int key) {
        int index = hashFunction(key);
        for (auto& kvp : table[index]) {
            if (kvp.first == key) {
                return kvp.second;
            }
        }
        return -1;
    }

    // remove function
    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                break;
            }
        }
    }
};

// main function for testing
int main() {
    HashTable ht;

    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    ht.insert(4, 40);
    ht.insert(5, 50);

    cout << ht.search(3) << endl;
    cout << ht.search(6) << endl;

    ht.remove(4);

    cout << ht.search(4) << endl;

    return 0;
}
