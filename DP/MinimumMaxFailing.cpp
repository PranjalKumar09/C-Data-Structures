#include <bits/stdc++.h>
using namespace std;

/* Minimum/Maximum Falling Path Sum */
int n, m;
vector<vector<int>> mat;



int fn_util(int i, int j)
{

    if (i == n)
        return 0;
    if (j < 0 || j > m - 1)
        return INT_MAX;

    return mat[i][j] + min(fn_util(i + 1, j - 1),
min(fn_util(i + 1, j),
    fn_util(i + 1, j + 1)));
}
int fn(){
    int ans = INT_MAX;
    for (int j = 0; j < m; j++)
        ans = min(ans, fn_util(0, j));
    return ans;
}

int fn_util2(int i, int j, vector<vector<int>>& dp)
{

    if (i == n)
        return 0;
    if (j < 0 || j > m - 1)
        return INT_MAX;
    if (dp[i][j] != INT_MAX)
        return dp[i][j];

    return dp[i][j] = mat[i][j] + min(fn_util2(i + 1, j - 1, dp),
min(fn_util2(i + 1, j, dp),
    fn_util2(i + 1, j + 1, dp)));
}
int fn2(){
    int ans = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    for (int j = 0; j < m; j++)
        ans = min(ans, fn_util2(0, j,dp));
    return ans;
}


int fn3()
{
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < m; i++)
        dp[n-1][i] = mat[n - 1][i];
    
    for (int i = n-2; i > -1 ; i--)
        for (int j = 0; j < m; j++) {
            dp[i][j] =  mat[i][j] + dp[i + 1][j];


            if (j!=0) dp[i][j] = min(dp[i][j], mat[i][j] + dp[i + 1][j - 1]);
            if (j!=m-1) dp[i][j] = min (dp[i][j]  , mat[i][j] + dp[i + 1][j + 1]);

        }
    

    int ans = INT_MAX;
    for (int j = 0; j < m; j++)
        ans = min(ans, dp[0][j]);
    return ans;
}





int fn4() {
    vector<int> dp(m); // Single row DP

    // Initialize last row
    for (int j = 0; j < m; j++)
        dp[j] = mat[n - 1][j];

    // Traverse from second last row to the top
    for (int i = n - 2; i >= 0; i--) {
        vector<int> cur(m, INT_MAX); // Temporary row for new calculations
        
        for (int j = 0; j < m; j++) {
            cur[j] = mat[i][j] + dp[j]; // From below
            
            if (j > 0) // From bottom-left diagonal
                cur[j] = min(cur[j], mat[i][j] + dp[j - 1]);

            if (j < m - 1) // From bottom-right diagonal
                cur[j] = min(cur[j], mat[i][j] + dp[j + 1]);
        }
        
        dp = cur; // Move cur to dp
    }

    return *min_element(dp.begin(), dp.end()); // Minimum value in first row
}



int getMaxPathSum(){
    // return fn();
    // return fn2();
    return fn3();

}



int main()
{
    // Define the matrix as a 2D vector
    mat ={{1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}};
    n = mat.size(), m = mat[0].size();

    // Call the getMaxPathSum function and print the result
    cout << getMaxPathSum()<<endl;

    return 0;
}
