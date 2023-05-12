//Ques: Implement a heap data structure and use it to sort an array of integers.

#include <iostream>
#include <vector>

using namespace std;

// heap class
class Heap {
private:
    vector<int> heap;

    // helper function to swap two elements in the heap
    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    // helper function to perform heapify operation at index i
    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(i, largest);
            heapify(largest);
        }
    }

public:
    // constructor to create a heap from an array of integers
    Heap(vector<int> arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    // function to extract the maximum element from the heap
    int extractMax() {
        int max = heap[0];
        swap(0, heap.size() - 1);
        heap.pop_back();
        heapify(0);
        return max;
    }

    // function to check if the heap is empty
    bool isEmpty() {
        return heap.size() == 0;
    }
};

// main function for testing
int main() {
    vector<int> arr = { 5, 3, 8, 4, 2, 1, 9, 7, 6 };
    Heap heap(arr);

    // sort the array using the heap
    while (!heap.isEmpty()) {
        cout << heap.extractMax() << " ";
    }
    cout << endl;

    return 0;
}
