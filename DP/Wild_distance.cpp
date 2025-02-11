#include <bits/stdc++.h>
using namespace std;

/* 
Wildcard Matching | (DP-34)

The code correctly handles the '*' wildcard without including f1(i-1, j-1) because the two existing cases cover all necessary scenarios:

    f1(i-1, j): Matches the '*' to zero characters, skipping it in the pattern (i-1) but keeping the string index (j).

    f1(i, j-1): Matches the '*' to one or more characters, keeping the pattern index (i) to allow further matches while advancing the string (j-1).
 */
string s1 = "?ay";
string s2 = "ray";

int l1 = s1.length(), l2 = s2.length();

bool f1(int i, int j) {
    if (i == -1 && j == -1) return true;
    if (i == -1) return false;
    if (j == -1) {
        for (int k = 0; k <= i; k++) {
            if (s1[k] != '*') return false;
        }
        return true;
    }
    if (s1[i] == '?' || s1[i] == s2[j]) return f1(i - 1, j - 1);
    if (s1[i] == '*') return f1(i - 1, j) || f1(i, j - 1);
    return false;
}

bool f2(int i, int j, vector<vector<int>>& dp) {
    if (i == -1 && j == -1) return true;
    if (i == -1) return false;
    if (j == -1) {
        for (int k = 0; k <= i; k++) {
            if (s1[k] != '*') return false;
        }
        return true;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i] == '?' || s1[i] == s2[j]) return dp[i][j] = f2(i - 1, j - 1, dp);
    if (s1[i] == '*') return dp[i][j] = f2(i - 1, j, dp) || f2(i, j - 1, dp);
    return dp[i][j] = 0;
}

bool f3() {
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= l1; i++) {
        dp[i][0] = (s1[i - 1] == '*') && dp[i - 1][0];
    }
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == '?' || s1[i - 1] == s2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];
            else if (s1[i - 1] == '*') 
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }
    return dp[l1][l2];
}

bool f4() {
    vector<bool> prev(l2 + 1, false), curr(l2 + 1, false);
    prev[0] = true;
    for (int i = 1; i <= l1; i++) {
        curr[0] = (s1[i - 1] == '*') && prev[0];
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == '?' || s1[i - 1] == s2[j - 1]) 
                curr[j] = prev[j - 1];
            else if (s1[i - 1] == '*') 
                curr[j] = prev[j] || curr[j - 1];
            else 
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[l2];
}




int main(){
    cout << f1(l1-1, l2-1) << endl;
    vector<vector<int> > dp(l1, vector<int> (l2, -1));
    cout << f2(l1-1, l2-1, dp) << endl;
    cout << f3() << endl;
    cout << f4() << endl;


    return 0;

}