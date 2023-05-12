/*Ques: Develop a dynamic programming algorithm for the edit distance problem in Cpp. Analyze the time and space complexity of your implementation and compare it
with the time and space complexity of a naive recursive implementation.*/

#include <iostream>
#include <cstring>
using namespace std;

int editDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    return dp[m][n];
}

int main() {
    string s1, s2;
    cout<<"Enter the first string: ";
    cin>>s1;
    cout<<"Enter the second string: ";
    cin>>s2;
    int ans = editDistance(s1, s2);
    cout<<"The minimum number of operations required to transform "<<s1<<" to "<<s2<<" is "<<ans<<endl;
    return 0;
}


/*Time Complexity:
The time complexity of the above implementation is O(m*n), where m and n are the lengths of the two strings. This is because we are filling an (m+1) x (n+1) 2D array.

Space Complexity:
The space complexity of the above implementation is O(m*n), where m and n are the lengths of the two strings. This is because we are using a 2D array of size (m+1) x (n+1) to store the minimum number of operations required to transform the substrings. However, we can optimize the space complexity to O(n) by using a 1D array instead of a 2D array.

Naive Recursive Implementation:
The naive recursive implementation has a time complexity of O(3^(m+n)), where m and n are the lengths of the two strings. This is because we are trying out all possible combinations of insertions, deletions, and substitutions to transform one string to another. The space complexity is O(m+n) due to the recursive calls.*/