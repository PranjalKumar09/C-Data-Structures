#include <bits/stdc++.h>

using namespace std;

/*
    Grid Unique Paths 2 

    Same like Grid Unique Paths but here just have blockade


*/

int n, m;
vector<vector<int>> maze;

int sol(int m, int n){
    if (m == 0 && n == 0) return 1;
    if (m < 0 || n < 0 || maze[m][n] == -1 ) return 0;
    return sol(m-1, n) + sol(m, n-1);
}

int sol2(int m, int n , vector<vector<int>>& dp){
    if (m == 0 && n == 0) return 1;
    if (m < 0 || n < 0 || maze[m][n] == -1) return 0;
    if (dp[m][n] != -1) return dp[m][n];
    return dp[m][n] = sol2(m-1, n, dp) + sol2(m, n-1, dp);
}

int sol3(){
    if (m < 0 || n < 0) return 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            if (maze[i][j] == -1) 
            dp[i][j] = 0;  // Blocked cell
            else {
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    
    return dp[m-1][n-1];

}

int sol4(){
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (maze[i][j] == -1)
                dp[j] = 0; // Blocked cell
            else if (j > 0)
                    dp[j] += dp[j - 1];
            
        }
        
    return dp[n-1];
}

int mazeObstacles(vector<vector<int> >& maze)
{
    // return sol(m-1,n-1);

    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return sol2(m-1, n-1, dp);

    return sol3();
}

int main()
{
    maze = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    n = maze.size();
    m = maze[0].size();

    cout << "Number of paths with obstacles: " << mazeObstacles(maze) << endl;
    return 0;
}
