#include <bits/stdc++.h>
using namespace std;

/*
    Cycle Detection in Undirected Graph

   i/p: int V, vector<pair <int, int>> & edges
   o/p: boolean
 */

bool dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj) {
    vis[node] = 1;
    for (auto v : adj[node]) {
        if (!vis[v]) {
            if (dfs(v, node, vis, adj))
                return true;
        }
        else if (v != parent) // cycle found
            return true;
    }
    return false;
}

bool solve(int v,vector<pair <int, int>> & edges){
    vector<vector<int> > adj(v);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        adj[u].push_back(edges[i].second);
    }
    vector<bool> visited(v, false);
    for (int i = 0 ; i < v; i++)
        if (!visited[i] && dfs(i,-1,visited,adj))
            return 1;
    return 0;
}




int main() {
    int numVertices = 5;
    
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4}
        ,{4, 0} // This edge creates a cycle
    };

    bool hasCycle = solve(numVertices, edges);
    
    if (hasCycle)
        cout << "The graph contains a cycle." << endl;
    else
        cout << "The graph does not contain a cycle." << endl;
    

    return 0;
}