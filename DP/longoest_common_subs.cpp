#include <bits/stdc++.h>
using namespace std;


// LONGEST COMMON SUBSEQUENCE
// dp[i][j]  ->

string s1 = "abcde",  s2 = "ace";
int l1 = s1.length(), l2 = s2.length();

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
    vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i-1] == s2[j-1])  
                dp[i][j] = dp[i-1][j-1] + 1;
            else  
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[l1][l2];
}
int f4(){
    vector<int> prev(l2+1, 0), curr(l2+1, 0);

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i-1] == s2[j-1]) 
                curr[j] = 1 + prev[j-1];
            else 
                curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr; // Move current row to previous row
    }
    return prev[l2]; // Correct LCS length
}




int main(){

    cout << f1(l1-1, l2-1) << endl;

    vector<vector<int>> dp(l1, vector<int>(l2, -1));

    cout << f2(l1-1, l2-1, dp) << endl;
    cout << f3() << endl;
    cout << f4() << endl;
    
    return 0;
}