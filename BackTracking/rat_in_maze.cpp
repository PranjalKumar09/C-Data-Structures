#include <bits/stdc++.h>
using namespace std;

/* 
Rat in Maze
===========

    TC = O(4^(m*n))
    SC = O(m*n)

*/
void solve(int i , int j ,vector<vector<int> > & grid, vector<string> &ans, string move, vector<vector<bool> > & vis){
    int n = grid.size();
    if (i == n-1 && j == n-1) {ans.push_back(move); return; }

    vector<int> di = {1,0,0,-1};
    vector<int> dj = {0,1,-1,0};

    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && grid[nexti][nextj] == 1 && !vis[nexti][nextj]) {
            vis[i][j] = 1;
            solve(nexti, nextj, grid, ans, move + dir[ind], vis);
            vis[i][j] = 0; 
        }
    } 
}


int main() {
    // Example grid
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int n = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<string> ans;

    solve(0, 0, grid, ans, "", vis);

    // Print all paths found
    for (string path : ans) 
        cout << path << endl;
    

    return 0;
}
