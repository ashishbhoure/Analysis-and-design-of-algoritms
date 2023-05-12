// Ques: Implement an insertion sort algorithm for an array of integers. 

#include <iostream>

using namespace std;

// insertion sort function
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// main function for testing
int main() {
    int arr[] = { 4, 2, 9, 5, 1, 8, 3, 7, 6 }; // example array
    int size = sizeof(arr) / sizeof(arr[0]); // calculate array size

    insertionSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
