#include <bits/stdc++.h>
using namespace std;

/*
    Bridge (Torjan's Algo)
    =========================


    row - 1, col -1   |  row - 1, col  |    row - 1, col + 1
    ----------------------------------------------------------
    row, col - 1      |     center     |    row , col + 1
    ----------------------------------------------------------
    row + 1, col -1   |  row + 1, col  |    row + 1, col + 1




    TC: O(N^2 + N*M*9)

        N*2 -> for nested loop
        N*M*9 -> overall dfs/bfs

    SC: O(N^2) {max queue space}

 */

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;

    q.push({row, col});

    int V = grid.size(); // Grid dimension

    while (!q.empty())
    {
        int crow = q.front().first;
        int ccol = q.front().second;
        q.pop();

        for (int delrow = -1; delrow <= 1; delrow++)
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                int newrow = crow + delrow;
                int newcol = ccol + delcol;

                // Boundary check and visit status
                if (newrow >= 0 && newrow < V && newcol >= 0 && newcol < V && !vis[newrow][newcol] && grid[newrow][newcol] == '1')
                {
                    vis[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }
    }
}

int solve(vector<vector<char>> &grid)
{
    int V = grid.size();
    vector<vector<int>> vis(V, vector<int>(V, 0));

    int cnt = 0; // To count the number of connected components (or "islands")
    for (int row = 0; row < V; ++row)
    {
        for (int col = 0; col < V; ++col)
        {
            if (!vis[row][col] && grid[row][col] == '1')
            {
                bfs(row, col, vis, grid);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    // Predefined grid (3x3 in this case)
    vector<vector<char>> grid = {
        {'1', '1', '0'},
        {'0', '0', '0'},
        {'1', '0', '1'}};

    int result = solve(grid);
    cout << "Number of connected components (islands): " << result << endl;

    return 0;
}
