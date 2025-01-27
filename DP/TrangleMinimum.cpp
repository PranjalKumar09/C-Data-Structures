#include <bits/stdc++.h>
using namespace std;

/* Minimum path sum in Triangular Grid (DP 11) */
int n;
vector<vector<int>> mat;


int fn(int i, int j){
    
    if (i == n)
        return 0;

    return mat[i][j] + min(fn(i + 1, j), fn(i + 1, j + 1));
}
int fn2(int i, int j, vector<vector<int>> &dp){
    
    if (i == n)
        return 0;
    
    if (dp[i][j] != INT_MAX)
        return dp[i][j];

    return dp[i][j] = mat[i][j] + min(fn2(i + 1, j, dp), fn2(i + 1, j + 1, dp));
}

int fn3()
{
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
        dp[n - 1][i] = mat[n - 1][i];
    
    for (int i = n-2; i > -1 ; i--)
        for (int j = 0; j <= i; j++) 
            dp[i][j] = mat[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
    

    return dp[0][0]; 
}

int fn4(){
    vector<int> dp(n, INT_MAX);

    for (int i = 0; i < n; i++)
        dp[i] = mat[n - 1][i];

    for (int i = n - 2; i > -1; i--)
        for (int j = 0; j <= i; j++)
            dp[j] = mat[i][j] + min(dp[j], dp[j + 1]);
    return dp[0];
}

/* int fn3 (){
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

} */

int main(){
    n = 4;
    mat = {
        {1},
        {2,3},
        {3,6,7},
        {8,9,6,10}
    };

    cout<<endl<<fn(0,0) << endl;


    vector<vector<int>> dp(n, vector<int>(n , INT_MAX));
    cout<<endl<<fn2(0,0, dp) << endl;

    cout << endl << fn3() << endl;
    cout << endl << fn4() << endl;






    return 0;
}