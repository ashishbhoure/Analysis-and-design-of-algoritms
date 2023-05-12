// Ques: Implement a selection sort algorithm for an array of integers. 

#include <iostream>

using namespace std;

// selection sort function
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// main function for testing
int main() {
    int arr[] = { 4, 2, 9, 5, 1, 8, 3, 7, 6 }; // example array
    int size = sizeof(arr) / sizeof(arr[0]); // calculate array size

    selectionSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
