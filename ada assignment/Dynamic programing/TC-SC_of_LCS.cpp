/*Ques : Implement the longest common subsequence problem using dynamic programming
in Cpp. Analyze the time and space complexity of your implementation and
compare it with the time and space complexity of a naive recursive implementation.*/

#include <iostream>
#include <cstring>
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    cout << "Length of longest common subsequence: " << lcs(s1, s2) << endl;
    return 0;
}


//Time and Space Complexity
/*The time complexity of this dynamic programming implementation is O(mn), where m and n are the lengths of the two input strings. This is because the algorithm fills in an m x n array, and each entry requires a constant amount of time to compute.

In contrast, a naive recursive implementation of the longest common subsequence problem would have a time complexity of O(2^(m+n)), which is exponential. This is because the recursive approach would need to explore all possible combinations of substrings in both input strings.

The space complexity of the dynamic programming implementation is O(mn), which is the size of the 2D array used to store intermediate results. In contrast, the recursive implementation would require O(m+n) stack space for the function calls, since each call would need to store its own copy of the input strings.*/