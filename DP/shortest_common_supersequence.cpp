#include <bits/stdc++.h>
using namespace std;
/* 
    Shortest common supersequence
        common length -> c
        length shortest sup -> l1 + l2 - len(lcs) 
        
        
*/



string s1 = "brute";
string s2 = "groot";    
int l1 = s1.length(), l2 = s2.length();

string f3() {
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1])  
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else  
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }



// from here onwards different

    string ans = "";
    int i = l1, j = l2;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans = s1[i - 1] + ans;
            i--; j--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            ans = s1[i - 1] + ans;
            i--;
        } 
        else {
            ans = s2[j - 1] + ans;
            j--;
        }
    }

    while (i > 0) {
        ans = s1[i - 1] + ans;
        i--;
    }

    while (j > 0) {
        ans = s2[j - 1] + ans;
        j--;
    }

    return ans;
}

int main() {
    cout << "Shortest Common Supersequence: " << f3() << endl;
    return 0;
}
