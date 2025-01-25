#include <bits/stdc++.h>
using namespace std;

/*
Minimum Path Sum In a Grid

*/

vector<vector<int>> matrix;
int n,  m;


int fn(int x, int y){
    if (x < 0 || y < 0) return INT_MAX;
    if (x==0 && y==0) return matrix[0][0];

    return min(fn(x-1, y) , fn(x, y-1)) + matrix[x][y];
}

int fn2(int x, int y, vector<vector<int>> &dp)
{
    if (x < 0 || y < 0) return INT_MAX;
    if (dp[x][y]!=INT_MAX) return dp[x][y];
    if (x==0 && y==0) return  dp[0][0] = matrix[0][0];

    return dp[x][y] = min(fn2(x - 1, y, dp), fn2(x, y - 1, dp)) + matrix[x][y];
}

int fn3()
{
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = matrix[0][0];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0 && j == 0) continue;
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]);
            dp[i][j] += matrix[i][j];
        }
    }

    return dp[n-1][m-1];
}

int fn4(){
    vector<int> dp(m, INT_MAX);
    dp[0] = matrix[0][0];

    for (int i = 0; i < n; i++){
        vector<int> cur(m, INT_MAX);

        for (int j = 0; j < m; j++){
            if (i == 0 && j == 0) {
                cur[j] = matrix[0][0];
                continue;
            }
            cur[j] = dp[j];
            if (j > 0) cur[j] = min(cur[j], cur[j-1]);
            cur[j] += matrix[i][j];
        }
        dp = cur;
        }
    return dp[m-1];
}
int minSumPath(){
    // return fn(n-1, m-1);

    // vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    // return fn3();

    return fn4();
}

    int
    main()
{
    matrix = {
        {5, 9, 6},
        {11, 5, 2}};

    n = matrix.size();
    m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath() << endl;
    return 0;

    return 0;
}
