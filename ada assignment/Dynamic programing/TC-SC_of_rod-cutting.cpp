/*Ques: Implement the rod-cutting problem using dynamic programming in Cpp.
Analyze the time and space complexity of your implementation and compare it with the
time and space complexity of a naive recursive implementation.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rod_cutting(int n, vector<int>& prices) {
    vector<int> dp(n + 1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_price = INT_MIN;

        for (int j = 1; j <= i; j++) {
            max_price = max(max_price, prices[j] + dp[i - j]);
        }

        dp[i] = max_price;
    }

    return dp[n];
}

int main() {
    int n = 8;
    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int max_profit = rod_cutting(n, prices);
    cout << "Maximum profit: " << max_profit << endl;
    return 0;
}


// Time and space complexity 
/*The time complexity of this implementation is O(n^2), since we have two nested loops that each iterate from 1 to n. The space complexity is also O(n), since we only need to store the values of dp[i] for each i.

In contrast, a naive recursive implementation would have a time complexity of O(2^n), since it would involve computing each possible combination of rod cuts. It would also have a space complexity of O(n), since it would need to store the recursion stack.*/