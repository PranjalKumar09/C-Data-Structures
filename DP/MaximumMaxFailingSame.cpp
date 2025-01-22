#include <bits/stdc++.h>
using namespace std;

/* Maximum Falling Path Sum 
    easy converting 
        INT_MAX to INT_MIN
        min to max

*/
int n, m;
vector<vector<int>> mat;



int fn_util(int i, int j)
{

    if (i == -1)
        return 0;
    if (j < 0 || j > m - 1)
        return INT_MIN;

    return mat[i][j] + max(fn_util(i - 1, j - 1),
max(fn_util(i - 1, j),
    fn_util(i - 1, j + 1)));
}
int fn(){
    int ans = INT_MIN;
    for (int j = 0; j < m; j++)
        ans = max(ans, fn_util(n-1, j));
    return ans;
}

int fn_util2(int i, int j, vector<vector<int>>& dp)
{

    if (i == -1)
        return 0;
    if (j < 0 || j > m - 1)
        return INT_MIN;
    if (dp[i][j] != INT_MIN)
        return dp[i][j];

    return dp[i][j] = mat[i][j] + max(fn_util2(i - 1, j - 1, dp),
max(fn_util2(i - 1, j, dp),
    fn_util2(i - 1, j + 1, dp)));
}
int fn2(){
    int ans = INT_MIN;
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

    for (int j = 0; j < m; j++)
        ans = max(ans, fn_util2(n-1, j,dp));
        
    return ans;
}


int fn3()
{
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

    for (int i = 0; i < m; i++)
        dp[0][i] = mat[0][i];
    
    for (int i = 1; i < n ; i++)
        for (int j = 0; j < m; j++) {
            dp[i][j] =  mat[i][j] + dp[i - 1][j];


            if (j!=0) dp[i][j] = max(dp[i][j], mat[i][j] + dp[i - 1][j - 1]);
            if (j!=m-1) dp[i][j] = min (dp[i][j]  , mat[i][j] + dp[i - 1][j + 1]);

        }
    

    int ans = INT_MIN;
    for (int j = 0; j < m; j++)
        ans = max(ans, dp[n-1][j]);
    return ans;
}





int fn4() {
    vector<int> dp(m); 

    for (int j = 0; j < m; j++)
        dp[j] = mat[0][j];

    for (int i = 1; i < n; i++) {
        vector<int> cur(m, INT_MIN); 
        
        for (int j = 0; j < m; j++) {
            cur[j] = mat[i][j] + dp[j];
            
            if (j > 0)
                cur[j] = max(cur[j], mat[i][j] + dp[j - 1]);

            if (j < m - 1)
                cur[j] = max(cur[j], mat[i][j] + dp[j + 1]);
        }
        
        dp = cur;
    }

    return *max_element(dp.begin(), dp.end());
}



int getMaxPathSum(){
    // return fn();
    // return fn2();
    // return fn3();
    return fn4();

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
