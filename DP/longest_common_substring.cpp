#include <bits/stdc++.h>
using namespace std;

string s1 = "abcjklp", s2 = "acjkp";


/* 
LONGEST COMMON SUBSTRING
dp[i][j] tells how long the longest common substring is if s1[i] and s2[j] are part of it.
 dp[j] stores the max substring length ending at s2[j] for current s1[i]

 */

int l1 = s1.length(), l2 = s2.length();

int f1_substring(int i, int j, int count) {
    if (i == -1 || j == -1) return count;

    int newCount = 0;
    if (s1[i] == s2[j]) 
        newCount = f1_substring(i-1, j-1, count + 1);

    return max({count, newCount, f1_substring(i-1, j, 0), f1_substring(i, j-1, 0)});
}



int f2(int i, int j, int count, vector<vector<int>>& dp){
    if (i == -1 || j == -1) return count;
    if (dp[i][j] != -1) return dp[i][j];

    int newCount = 0;
    if (s1[i] == s2[j]) 
        newCount = f2(i-1, j-1, count + 1, dp);

    return dp[i][j] = max({count, newCount, f2(i-1, j, 0, dp), f2(i, j-1, 0, dp)});
}

int f3(){
    // vector<vector<int>> dp(l1, vector<int>(l2, 9));

vector<vector<int>> dp(l1, vector<int>(l2, 0)); // Initialize DP table
    int maxLen = 0;

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            if (s1[i] == s2[j]) { 
                dp[i][j] = (i > 0 && j > 0) ? 1 + dp[i-1][j-1] : 1;
                maxLen = max(maxLen, dp[i][j]); // Track max length
            }
        }
    }
    
    return maxLen;
}








int f5(){

  vector<int> prev(l2, 0), curr(l2, 0); // Only two 1D DP arrays
    int maxLen = 0;

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            if (s1[i] == s2[j]) {
                curr[j] = (i > 0 && j > 0) ? 1 + prev[j-1] : 1;
                maxLen = max(maxLen, curr[j]);
            } else {
                curr[j] = 0; // Reset if mismatch
            }
        }
        prev = curr; // Move current row to previous row
    }

    return maxLen;
}



string longestPalindromeHelper() {
    // TODO Fix this not works anymore  
     // This function for returning string itself
    vector<int> prev(l1 + 1, 0), curr(l1 + 1, 0); 
    int maxLen = 0;
    int maxEnd = 0;  // To track the end index of the longest palindrome
    
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
                if (curr[j] > maxLen) {
                    maxLen = curr[j];
                    maxEnd = i - 1;  // Store the end index of the palindrome
                }
            } else {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    
    int maxStart = maxEnd - maxLen + 1;
    return s1.substr(maxStart, maxLen);
}


int main(){

    cout << f1_substring(l1-1, l2-1, 0) << endl;

    vector<vector<int>> dp(l1, vector<int>(l2, -1));

    cout << f2(l1-1, l2-1, 0, dp) << endl;
    cout << f3() << endl;
    cout << f5() << endl;
    
    return 0;
}