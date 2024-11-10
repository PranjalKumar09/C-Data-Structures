#include <bits/stdc++.h>
using namespace std;

/*
    DFS
    ===
    Death First Search

    TC = O(N+2E)
    SC = O(E)
 */

void dfs(int node, vector<int>& vis, vector<int>& ans, vector<vector<int>>& adj) {
    vis[node] = 1;
    ans.push_back(node);

    for (auto v : adj[node])
        if (!vis[v])
            dfs(v, vis, ans, adj);
        
    
}

vector<int> solve(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);
    vector<int> ans;

    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i, vis, ans, adj);
        
    

    return ans;
}

int main() {
    int V = 5;
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2, 4},
        {3}
    };

    vector<int> result = solve(V, adj);

    for (int node : result)
        cout << node << " ";
    

    return 0;
}