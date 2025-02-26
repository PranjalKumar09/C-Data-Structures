#include <bits/stdc++.h>
using namespace std;


/* 
DISTINCT SUBSEQUENCE
    




 */


string s1 = "rabbbit";
string s2 = "rabbit";    // s2 is target to be search
int l1 = s1.length(), l2 = s2.length();


int f1(int i, int j){
    if (j == -1) return 1;
    if (i == -1) return 0;

    if (s1[i] == s2[j]) return f1(i-1, j-1) + f1(i-1, j);

    return f1(i-1, j);
}

int f2(int i, int j, vector<vector<int> > &dp){
    if (j == -1) return 1;
    if (i == -1) return 0;
    if (dp[i][j]!= -1) return dp[i][j];

    if (s1[i] == s2[j]) return dp[i][j] = f2(i-1, j-1, dp) + f2(i-1, j, dp);

    return dp[i][j] = f2(i-1, j, dp);
}



int f3(){
    vector<vector<int> > dp(l1+1, vector<int>(l2+1,0 ));;
    
    for (int i = 0; i < l1; i++) dp[i][0] = 1;
    
    for (int i = 1; i <= l1; i++){
        for (int j = 1; j <= l2; j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[l1][l2];
}


int f4(){


    // here every j demands j-1 , so we cant overwrite j-1 so instead do backward iteration
    vector<int>  dp(l2+1,0 );
    
    dp[0] = 1;
    
    for (int i = 1; i <= l1; i++){
        for (int j = l2; j > 0; j--){
            if (s1[i-1] == s2[j-1]) dp[j] = dp[j-1] + dp[j];
            else dp[j] = dp[j];
        }
    }
    return dp[l2];
}








int main(){
    cout << f1(l1-1, l2-1) << endl;

    vector<vector<int>> dp(l1, vector<int>(l2, -1));
    cout << f2(l1-1, l2-1, dp) << endl;

    cout << f3()<< endl;
    cout << f4()<< endl;

}