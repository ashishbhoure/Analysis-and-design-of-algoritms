//Ques:  Implement a linear search algorithm for an array of integers.

#include <iostream>

using namespace std;

// linear search function
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// main function for testing
int main() {
    int arr[] = { 4, 2, 9, 5, 1, 8, 3, 7, 6 }; // example array
    int size = sizeof(arr) / sizeof(arr[0]); // calculate array size

    int key = 5; // example key to search for
    int index = linearSearch(arr, size, key); // perform linear search

    if (index != -1) {
        cout << "Key found at index " << index << endl;
    }
    else {
        cout << "Key not found" << endl;
    }

    return 0;
}
