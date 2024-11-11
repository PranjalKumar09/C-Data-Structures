#include <bits/stdc++.h>
using namespace std;

/*
    Distance of nearest cell having 1
    =================================

    i/p   ->  o/p -> vector <vector<int> >
    1 0 1     0 1 0
    1 1 0     0 0 1
    1 0 0     0 1 2



    TC = O(N*M)(1+4)
    SC = O(N*M)(3)

 */


vector<vector<int>> solve(vector<vector<int>>& ip) {
    int n = ip.size(), m = ip[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0)), dist(n, vector<int>(m, INT_MAX));

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ip[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
                dist[i][j] = 0;
            }
        }
    }

    vector<int> del_row = {-1, 1, 0, 0}, del_col = {0, 0, 1, -1};

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int n_row = row + del_row[i];
            int n_col = col + del_col[i];
            if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m && !vis[n_row][n_col]) {
                q.push({{n_row, n_col}, steps + 1});
                vis[n_row][n_col] = 1;
                dist[n_row][n_col] = steps + 1;
            }
        }
    }
    return dist;
}

int main() {
    // Define a sample 2D grid
    vector<vector<int>> ip = {
        {0, 0, 1, 0 , 0},
        {0, 0, 0, 0 , 0},
        {1, 0, 0, 0 , 0},
        {0, 0, 0, 1 , 0}
    };

    vector<vector<int>> result = solve(ip);

    // Print the distance matrix
    for (const auto& row : result) {
        for (int cell : row) {
            if (cell == INT_MAX)
                cout << "INF ";
            else
                cout << cell << " ";
            
        }
        cout << endl;
    }

    return 0;
}