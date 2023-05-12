/*Ques: Implement a dynamic programming algorithm to find the maximum sum subarray
in Cpp. Analyze the time and space complexity of your implementation and
compare it with the time and space complexity of a naive brute-force approach.*/

#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int>& nums) {
    int n = nums.size();
    int max_so_far = nums[0], max_ending_here = nums[0];
    for (int i = 1; i < n; i++) {
        max_ending_here = max(nums[i], max_ending_here + nums[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum sum subarray: " << maxSubarraySum(nums) << endl;
    return 0;
}

//Time cpmplexity
/*The time complexity of this algorithm is O(n) because we only iterate over the array once. The space complexity is O(1) because we only use two variables to keep track of the maximum sum subarrays.

On the other hand, the naive brute-force approach would involve iterating over all possible subarrays and finding their sum. This would have a time complexity of O(n^2). The space complexity would also be O(1) because we only need to store the sum of the current subarray. */