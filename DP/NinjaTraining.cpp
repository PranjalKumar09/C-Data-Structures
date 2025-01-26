#include <bits/stdc++.h>

using namespace std;

/*
Ninja Training


    so we have to maintain the last task
    0, 1, 2 for tasks & 3 for starting

 */


int solve(int i, int last, const vector<vector<int>> &points){
    if (i < 0) return 0;
    if (last == 3){
        return max(
            solve(i-1,0, points) + points[i][0],
            max(solve(i-1,1, points) + points[i][1], 
                solve(i-1,2, points) + points[i][2])
        );
    }
    return max(
        solve(i - 1, (last + 1) % 3, points) + points[i][ (last + 1) % 3],
        solve(i - 1, (last + 2) % 3, points) + points[i][ (last + 2) % 3]);
}
int solve2(int i, int last, const vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (i < 0) return 0;

    
    if (last == 3){
        dp[i][0] = solve2(i-1,0, points, dp) + points[i][0];
        dp[i][1] = solve2(i-1,1, points, dp) + points[i][1];
        dp[i][2] = solve2(i-1,2, points, dp) + points[i][2];
        return max( dp[i][0], max(dp[i][1], dp[i][2]
        ));
    }

    if (dp[i][last] != -1) return dp[i][last];

    return dp[i][last] = max(
        solve2(i - 1, (last + 1) % 3, points, dp) + points[i][ (last + 1) % 3],
        solve2(i - 1, (last + 2) % 3, points, dp) + points[i][ (last + 2) % 3]);
}

int solve3(const vector<vector<int>> &points){
    int n = points.size();
    vector<vector<int>> dp(points.size(), vector<int>(3, -1));

    dp[0][0] = points[0][0]; dp[0][1] = points[0][1]; dp[0][2] = points[0][2];


    for (int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + points[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + points[i][1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + points[i][2];
    }
    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}

int solve4(const vector<vector<int>> &points){
    int n = points.size();
    vector<int> dp(3);

    dp[0] = points[0][0], dp[1] = points[0][1], dp[2] = points[0][2];


    for (int i = 1; i < n; i++){
        vector<int> temp(3);
        temp[0] = max(dp[1], dp[2]) + points[i][0];
        temp[1] = max(dp[0], dp[2]) + points[i][1];
        temp[2] = max(dp[0], dp[1]) + points[i][2];

        dp[0] = temp[0], dp[1] = temp[1], dp[2] = temp[2];
    }
    return max(dp[0], max(dp[1], dp[2]));
}

    int ninjaTraining(const vector<vector<int>> &points)
{
    int n = points.size();

    // return solve(n-1,3,points);

    // vector<vector<int>> dp(points.size(), vector<int>(3, -1));
    // return solve2(n-1,3, points, dp);

    // return solve3(points);
    return solve4(points);
}

int main()
{
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};

    cout << ninjaTraining(points);



    cout <<  endl;
}
