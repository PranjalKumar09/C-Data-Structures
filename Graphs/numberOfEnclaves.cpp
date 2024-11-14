#include <bits/stdc++.h>
using namespace std;


/*
    Number of Enclaves
    ==================
    return no of land cells in which walk off boundary of grid walk off boundary


    
    TC: O(N*M*4)
    SC: O(N*M)    queue visited


    0 0 0 0
    1 0 1 0
    0 1 1 0
    0 0 0 0     o/p: 3
*/

int solve(vector<vector<int>> &grid){
    queue <pair<int,int> > q;
    int n = grid.size() , m = grid[0].size();

    vector<vector<bool> > vis(n, vector<bool>(m,false));

    for (int i = 0; i < n; i++)
        for (int j = 0 ; j < m; j++)
            if (i == 0 || j == 0 || i == n-1 || j == m-1)
                if (grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = true;
                }

    vector<int> dx = {0,0,1,-1}, dy = {1,-1,0,0};

    while(!q.empty()){ // Repeat until queue becomes empty
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && ncol < n && nrow >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]){
                // check valid coordinate & for land cell
                q.push({nrow,ncol});
                vis[nrow][ncol] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] && !vis[i][j])   cnt++;

    return cnt;
}


int main() {
    // Example test case
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    // Call the solve function and print the result
    cout << "Number of enclaves: " << solve(grid) << endl;

    return 0;
}
