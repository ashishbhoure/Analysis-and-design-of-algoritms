
// Ques: Implement a binary search algorithm for an array of integers. 

#include <iostream>
#include <vector>

using namespace std;

// binary search function
int binarySearch(vector<int> arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1; // key not found
}

// main function for testing
int main() {
    vector<int> arr { 1, 3, 4, 7, 8, 9, 11, 15, 19, 25 }; // example array
    int key = 7; // example key to search for

    int index = binarySearch(arr, key);

    if (index != -1) {
        cout << "Key found at index: " << index << endl;
    }
    else {
        cout << "Key not found." << endl;
    }

    return 0;
}
