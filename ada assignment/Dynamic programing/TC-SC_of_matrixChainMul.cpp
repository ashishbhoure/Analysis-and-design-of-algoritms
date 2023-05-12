/*Ques: Implement the matrix chain multiplication problem using dynamic programming in
Cppp. Analyze the time and space complexity of your implementation and
compare it with the time and space complexity of a naive recursive implementation.*/

#include <iostream>
#include <vector>
using namespace std;

int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    vector<int> p = {10, 20, 30, 40, 50};
    cout << "Minimum number of multiplications: " << matrixChainOrder(p) << endl;
    return 0;
}


//Time and Space Complexity
/*The time complexity of this implementation is O(n^3), where n is the number of matrices in the chain. The space complexity is also O(n^2) due to the use of a 2D vector for the dynamic programming table.

In comparison, a naive recursive implementation of the matrix chain multiplication problem has an exponential time complexity of O(2^n), where n is the number of matrices in the chain. The space complexity of the recursive implementation is O(n) due to the use of the function call stack. */