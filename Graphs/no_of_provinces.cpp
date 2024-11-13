#include <bits/stdc++.h>
using namespace std;

/*
    No of Provinces
    ===============

    No of unconnected parts

    TC = O(V^2) + O(V+2E)
    SC = O(2V)
 */

void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
    vis[node] = 1;

    for (auto v : adj[node]) {
        if (!vis[v]) {
            dfs(v, vis, adj);
        }
    }
}

int solve(int V, vector<vector<int>> adj) {
    vector<vector<int>> adjLs(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j]) {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    vector<int> vis(V, 0);  // Initialize visited array with 0 (unvisited)
    int cnt = 0;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i, vis, adjLs);
        }
    }

    return cnt;
}

int main(){
    int V = 5;
    vector<vector<int>> adj = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    int provinces = solve(V, adj);
    cout << "Number of Provinces: " << provinces << endl;

    return 0;
}