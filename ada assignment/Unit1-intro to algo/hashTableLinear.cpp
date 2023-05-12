//Ques: Implement a hash table data structure using linear probing collision resolution.

#include <iostream>
#include <vector>

using namespace std;

// hash table class
class HashTable {
private:
    static const int capacity = 10; // capacity of the hash table
    vector<pair<int, int>> table; // vector of pairs to store key-value pairs

public:
    HashTable() {
        // initialize the hash table with empty key-value pairs
        for (int i = 0; i < capacity; i++) {
            table.push_back(make_pair(-1, -1));
        }
    }

    // hash function
    int hashFunction(int key) {
        return key % capacity;
    }

    // insert function
    void insert(int key, int value) {
        int index = hashFunction(key);
        int i = index;
        while (table[i].first != -1 && table[i].first != key) {
            i = (i + 1) % capacity;
            if (i == index) {
                // the hash table is full
                return;
            }
        }
        table[i] = make_pair(key, value);
    }

    // search function
    int search(int key) {
        int index = hashFunction(key);
        int i = index;
        while (table[i].first != -1) {
            if (table[i].first == key) {
                return table[i].second;
            }
            i = (i + 1) % capacity;
            if (i == index) {
                // the key is not in the hash table
                return -1;
            }
        }
        return -1;
    }

    // remove function
    void remove(int key) {
        int index = hashFunction(key);
        int i = index;
        while (table[i].first != -1) {
            if (table[i].first == key) {
                table[i] = make_pair(-1, -1);
                int j = (i + 1) % capacity;
                while (table[j].first != -1) {
                    int h = hashFunction(table[j].first);
                    if ((j > i && (h <= i || h > j)) || (j < i && h <= i && h > j)) {
                        table[i] = table[j];
                        table[j] = make_pair(-1, -1);
                        i = j;
                    }
                    j = (j + 1) % capacity;
                }
                return;
            }
            i = (i + 1) % capacity;
            if (i == index) {
                // the key is not in the hash table
                return;
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
