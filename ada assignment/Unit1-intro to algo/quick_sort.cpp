//Ques: Implement a quick sort algorithm for an array of integers.

#include <iostream>

using namespace std;

// partition function
int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // pivot element
    int i = left - 1; // index of smaller element

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// quick sort function
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

// main function for testing
int main() {
    int arr[] = { 4, 2, 9, 5, 1, 8, 3, 7, 6 }; // example array
    int size = sizeof(arr) / sizeof(arr[0]); // calculate array size

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
