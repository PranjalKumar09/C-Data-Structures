#include <bits/stdc++.h>
using namespace std;

/*
    Flood Fill Algorithm
    ====================
    i/p:  vector<vector<int> > & image, int sr, int sc ,int newColor
    sr,sc -> starting new , starting color

    Only Same colour connected to 4 with new colour


    TC- O(N*M)(1+4)
    Worst TC WHEN ALL 4 neighbour have same colour

    SC- O(N*M)
    (input array + stack space at N*M)
*/


void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, vector<int>& delRow, vector<int>& delCol, int iniColor) {
    ans[row][col] = newColor;
    int n = image.size(), m = image[0].size();
    for (int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
        }
    }
}

// Solve function to initiate flood fill
vector<vector<int>> solve(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image; // Do not change the original
    vector<int> delRow = {-1, 1, 0, 0}; // Direction vectors for row movements
    vector<int> delCol = {0, 0, -1, 1}; // Direction vectors for column movements
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
    return ans;
}





int main() {
    // Define the image as a 2D vector
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    // Starting row and column for the flood fill
    int sr = 1; // starting row
    int sc = 1; // starting column

    // New color to apply
    int newColor = 2;

    // Perform the flood fill
    vector<vector<int>> result = solve(image, sr, sc, newColor);

    // Output the result
    cout << "Resulting image after flood fill:" << endl;
    for (const auto& row : result) {
        for (int color : row) {
            cout << color << ' ';
        }
        cout << endl;
    }

    return 0;
}