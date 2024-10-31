#include <bits/stdc++.h>
using namespace std;

/*
    Rotten Orange
    =============

    2 represent rotten orange
    1 represent fresh orange
    0 represent empty cell

    Every minute if fresh orange adjacent to rotten orange in 4 direction
    Return minimum time none of fresh orange, if not possible return -1

    i/p : vector<vector<int>>
    o/p : int

    TC: O(4*n^2)
    SC: O(n^2) (Worst SC case when every orange is rotten)
*/

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    queue<pair<int, int>> q;
    int freshCount = 0;
    int minutes = 0;
    
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1)
                freshCount++;
            
        }

    if (freshCount == 0) return 0;

    while (!q.empty()) {
        int size = q.size();
        bool rotted = false;
        
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    q.push({newX, newY});
                    freshCount--;
                    rotted = true;
                }
            }
        }
        
        if (rotted) minutes++;
    }

    return freshCount == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    
    int result = orangesRotting(grid);
    if (result != -1)
        cout << "All oranges will rot in " << result << " minutes." << endl;
    else
        cout << "Not all oranges can rot." << endl;

    return 0;
}