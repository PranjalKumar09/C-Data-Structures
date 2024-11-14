    #include <bits/stdc++.h>
    using namespace std;

    /*
        Shortest distance in Binary Maze by 4 direction
        ===============================================
        

        i/p: Matrix vector<vector<int>>, pair<int, int> source, destination
        if path not possible return -1

        TC: O(4*N*M) -> 4 direction Matrix
        SC: O(N*M) -> Distance or array


    */

    int solve2(pair<int, int> source, pair<int, int> destination, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Check if source or destination are walls
        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
        {
            return -1;
        }

        // If source is the same as destination

        if (source == destination)
        {
            return 0;
        }

        // Queue to store {row, col} positions
        queue<pair<int, int>> q;

        // Distance matrix
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // Starting point distance is 0
        dist[source.first][source.second] = 0;
        q.push(source);

        // Direction vectors for 4 possible movements (left, right, up, down)
        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {-1, 1, 0, 0};

        // BFS loop
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Check all 4 directions
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Validating the new position
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dist[r][c] + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = dist[r][c] + 1;

                    if (newr == destination.first && newc == destination.second)
                        return dist[newr][newc];
                    

                    q.push({newr, newc});
                }
            }
        }

        // If destination is not reachable
        return -1;
    }
  
    int main()
    {
        vector<vector<int>> grid = {
            {1, 0, 1, 1, 1},
            {1, 1, 1, 0, 1},
            {0, 1, 0, 1, 1},
            {1, 1, 1, 1, 0},
            {0, 0, 1, 1, 1}};

        pair<int, int> source = {0, 0};
        pair<int, int> destination = {4, 4};

        int result = solve2(source, destination, grid);

        if (result != -1)
            cout << "The shortest path is: " << result << endl;
        
        else
            cout << "Path not possible" << endl;
        

        return 0;
    }


    