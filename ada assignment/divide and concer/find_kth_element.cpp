/*Ques: Implement a divide-and-conquer algorithm for finding the kth largest element in an
unsorted array of integers. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int left, int right, int pivotIndex)
{
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;
    for (int i = left; i < right; i++)
    {
        if (arr[i] > pivotValue)
        {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

int kthLargest(vector<int>& arr, int left, int right, int k)
{
    if (left == right)
        return arr[left];

    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == pivotIndex)
        return arr[k];
    else if (k < pivotIndex)
        return kthLargest(arr, left, pivotIndex - 1, k);
    else
        return kthLargest(arr, pivotIndex + 1, right, k);
}

int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int k = 2;

    int kthLargestElement = kthLargest(arr, 0, arr.size() - 1, arr.size() - k);

    cout << "The " << k << "th largest element is: " << kthLargestElement << endl;

    return 0;
}
