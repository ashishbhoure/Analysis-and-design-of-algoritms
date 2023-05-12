/*Ques: Develop a dynamic programming algorithm to find the longest increasing
subsequence in Cpp. Analyze the time and space complexity of your
implementation and compare it with the time and space complexity of a brute-force
approach*/

#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLength = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                maxLength = max(maxLength, dp[i]);
            }
        }
    }
    return maxLength;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int maxLength = longestIncreasingSubsequence(nums);
    cout << "The length of the longest increasing subsequence is " << maxLength << endl;
    return 0;
}


//Time and space complexity
/*The time complexity of this algorithm is O(n^2), where n is the length of the input array. This is because we have a nested loop that iterates over all pairs of indices in the input array. The space complexity is also O(n), because we create a dp vector of size n to store the lengths of the longest increasing subsequences up to each index in the input array.

In comparison, a brute-force approach would involve generating all subsequences of the input array and checking whether each subsequence is increasing. The time complexity of this approach would be O(2^n), which is much worse than the dynamic programming approach. The space complexity of the brute-force approach would also be O(2^n), because we would need to store all the subsequences.*/