#include <bits/stdc++.h>

using namespace std;

/*
    Grid Unique Paths

*/

int sol(int m, int n){
    if (m == 0 && n == 0) return 1;
    if (m < 0 || n < 0) return 0;
    return sol(m-1, n) + sol(m, n-1);
}

int sol2(int m, int n, vector<vector<int>> & dp){
    if (m == 0 && n == 0) return 1;
    if (m < 0 || n < 0) return 0;
    if (dp[m][n] != -1) return dp[m][n];
    return dp[m][n] = sol2(m-1, n, dp) + sol2(m, n-1, dp);
}

int sol3(int m , int n){
    if (m < 0 || n < 0) return 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
    
    return dp[m-1][n-1];

}
int sol4(int m, int n)
{
    if (m < 0 || n < 0)
        return 0;

    vector<int> dp(n, 1); // Only a single row of size `n`

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[j] += dp[j - 1]; // Updating the current column

    return dp[n - 1]; // Last element contains the answer
}
int sol5(int m, int n)
{
    int ans = 1;
    for (int i = m; i < m+n-1;i++){
    ans =  (ans * i )/(i+1-m);}
    return ans;
}

int countWays(int m, int n){
    // return sol(m-1,n-1);

    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return sol2(m-1, n-1, dp);

    return sol4(m, n);
}




    int
    main()
{
    int m = 3;
    int n = 3;

    // Call the countWays function and print the result.
    cout << "Number of ways to reach "  << countWays(m, n)<<  endl;

    return 0;
}
