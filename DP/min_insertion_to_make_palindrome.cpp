#include <bits/stdc++.h>
using namespace std;

/* 
    Minimum no of insertion to make string Palindrome

    string stl -> l - LPS_fn( )

    LPS_fn is Longest Palindrome Subsequence



 */

string s1 = "abcaa";
string s2 = string(s1.rbegin(), s1.rend());    
int l = s1.length();

int f1(int i, int j){
    if (i == -1 || j == -1) return 0;
    if (s1[i] == s2[j]) return 1 + f1(i-1, j-1);
    return max(f1(i-1, j), f1(i, j-1));
}


int f2(int i, int j, vector<vector<int>>& dp){
    if (i == -1 || j == -1) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    if (s1[i] == s2[j]) return dp[i][j] = 1 + f2(i-1, j-1, dp);
    return dp[i][j] = max(f2(i-1, j, dp), f2(i, j-1, dp));
}

int f3(){
    vector<vector<int>> dp(l, vector<int>(l, 0));


    for (int i = 0; i < l; i++) 
        for (int j = 0; j < l; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = 1;
                if (i-1 != -1 && j-1 != -1)
                dp[i][j] += dp[i-1][j-1];
                }
            else {
                if (i-1 != -1)
                dp[i][j] =dp[i-1][j];
                if (j-1 != -1)
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
                
                }
           
        }
    
    return dp[l-1][l-1];
}


int f4(){

    vector<int> prev(l, -1), curr(l, -1); // No +1 size

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if (s1[i] == s2[j]) 
                curr[j] = (i > 0 && j > 0) ? 1 + prev[j-1] : 1;
            else {
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? curr[j-1] : 0;
                curr[j] = max(up, left);
            }
        }
        prev = curr; // Move current row to previous row
    }
    
    return prev[l-1]; // LCS length
}






int main(){

    cout << l - f1(l-1, l-1) << endl;

    vector<vector<int>> dp(l, vector<int>(l, -1));

    cout << l - f2(l-1, l-1, dp) << endl;
    cout << l - f3() << endl;
    cout << l -f4() << endl;
    
    return 0;
}