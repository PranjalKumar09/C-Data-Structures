/* 
link-> https://leetcode.com/problems/minimum-falling-path-sum-ii/solutions/5073439/easy-to-understand-short-concise-iterative-dp/

* from column we have to choice every rw
* greedy will fail 
* we hace option




 */

#include <bits/stdc++.h>
using namespace std;
class Solution1 {
    public:

    
    int n;
    void print(vector<int> &result){
        for(int i=0;i<n;i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
   int solve(int col, int row, vector<vector<int>>& grid) {
        if (row == n - 1) return grid[row][col]; // Base case

        int ans = INT_MAX;
        for (int nextCol = 0; nextCol < n; nextCol++)
            if (nextCol != col) // Ensure not to choose the same column again
                ans = min(ans, solve(nextCol, row + 1, grid));

        return grid[row][col] + ans;
    }


    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int result = INT_MAX;
        for (int col = 0; col <  n; col++) {
            result = min(result, solve(col, 0, grid));}
        return result;   

    }
};
class Solution2 {
public:
    vector<vector<int>> dp;
    int n;

    Solution2(int rows) : dp(rows, vector<int>(rows, -1)) {} // Constructor to initialize dp with -1


     void printDP() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }

    int solve(int col, int row, vector<vector<int>>& grid) {
        if (row >= n ) return 0; // Base case

        if (dp[row][col] != -1) return dp[row][col];

        int ans = INT_MAX;
        for (int nextCol = 0; nextCol < n; nextCol++)
            if (nextCol != col) // Ensure not to choose the same column again
                ans = min(ans, solve(nextCol, row + 1, grid));

        return dp[row][col] = grid[row][col] + ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, solve(col, 0, grid));
        }
        return result;
    }
};
class Solution3 {
    void printDp(vector<int>& dp) {
        for (int i = 0; i < dp.size(); ++i) {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dp(n, 0);
        for (int row = 0; row < n; row++) {
            vector<int> next(n);
            for (int col = 0; col < n; col++) {
                int minValue = INT_MAX;
                for (int i = 0; i < n; i++) {
                    if (i == col)
                        continue;
                    minValue = min(minValue, dp[i]);
                }
                if (minValue == INT_MAX)
                    minValue = 0;
                next[col] = minValue + grid[row][col];
            }
            cout << "next ";
            printDp(next);
            cout << endl;
            cout << "dp   ";
            cout << endl;

            printDp(dp);
            dp = next;
        }
        return *min_element(dp.begin(), dp.end());
    }
};



// but this will give error as it is recursive


int main() {
    Solution1 s1;
    vector<vector<int> > grid = {{1,2,3},{4,5,6},{7,8,9}};
    cout << s1.minFallingPathSum(grid) << endl;

    Solution2 s2(grid.size());
    cout << s2.minFallingPathSum(grid) << endl;

    // s2.printDP();

    Solution3 s3;
    cout << s3.minFallingPathSum(grid) << endl;

    return 0;
}