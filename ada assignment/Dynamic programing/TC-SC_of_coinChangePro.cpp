/*Ques: Develop a dynamic programming algorithm for the coin change problem in Cpp. Analyze the time and space complexity of your implementation and compare it
with the time and space complexity of a greedy algorithm.*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl; // Output: 3
    return 0;
}


//Time complexity
/*The time complexity of this implementation is O(n*amount), where n is the number of coins and amount is the target amount. The space complexity is O(amount) since we are using a 1D vector to store the intermediate results.*/