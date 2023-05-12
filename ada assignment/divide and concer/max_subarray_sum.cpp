/*Ques: Implement a divide-and-conquer algorithm for finding the maximum subarray sum of
a given array of integers. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCrossingSubarray(vector<int>& arr, int low, int mid, int high) {
    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return max(max(leftSum + rightSum, leftSum), rightSum);
}

int maxSubarraySum(vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int leftSum = maxSubarraySum(arr, low, mid);
    int rightSum = maxSubarraySum(arr, mid + 1, high);
    int crossSum = maxCrossingSubarray(arr, low, mid, high);
    return max(max(leftSum, rightSum), crossSum);
}

int main() {
    vector<int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = arr.size();
    int result = maxSubarraySum(arr, 0, n - 1);
    cout << "The maximum subarray sum of the given array is " << result << endl;
    return 0;
}
