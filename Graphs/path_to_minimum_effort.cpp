#include <bits/stdc++.h>
using namespace std;

/*
    Path with minimum effort of (max effort in path)
    ================================================

    0, 0 -> Source
    n, m -> Destination

0907


Good design is innovative
Good design makes a product useful
Good design is aesthetic
Good design makes a product understandable
Good design is unobtrusive
Good design is honest
Good design is long-lasting
Good design is thorough down to the last detail
Good design is environment friendly
Good design is as little design as possible


    Dijkstra  -> Shortest path, soucrce , destiantion
 */

int solve(vector<vector<int>> &grid)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    // Start point
    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int curr_cost = top.first;
        int curr_row = top.second.first;
        int curr_col = top.second.second;

        // If we reach the bottom-right corner
        if (curr_row == n - 1 && curr_col == m - 1)
        {
            return curr_cost;
        }

        // Explore all possible directions
        for (auto dir : directions)
        {
            int new_row = curr_row + dir.first;
            int new_col = curr_col + dir.second;

            // Check bounds and if the cell can be traversed (assuming 1 is traversable)
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == 1)
            {
                int new_cost = curr_cost + grid[new_row][new_col];
                // If the new cost is less than the recorded distance
                if (new_cost < dist[new_row][new_col])
                {
                    dist[new_row][new_col] = new_cost;
                    pq.push({new_cost, {new_row, new_col}});
                }
            }
        }
    }

    // If we did not find a path to the bottom-right corner, return -1 or an appropriate value
    return -1; // Assuming -1 indicates no valid path found
}
int main()
{

    return 0;
}