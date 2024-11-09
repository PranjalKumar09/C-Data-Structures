#include <bits/stdc++.h>
using namespace std;

/*
    Cycle Detection in Undirected Graph

    Methods:
        1) Using BFS
        2) Using DFS

    SC = o(2n)
    TC = o(v)+(v+2e)
 */
bool bfs(int src, vector<vector<int>>& adj, vector<int>& vis) {
    vis[src] = 1;
    queue<pair<int, int>> q; // {node, parent}
    q.push({src, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }
            else if (adjNode != parent) // cycle found
                return true;
        }
    }
    return false; // no cycle found
}

bool solve1(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (bfs(i, adj, vis))
                return true;
        }
    }
    return false; // no cycle found
}

// DFS function
bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {
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

bool solve2(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
        if (!vis[i])
            if (dfs(i, -1, vis, adj))
                return true;
        
    
    return false; // no cycle found
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

//
    adj[3].push_back(0);
    adj[0].push_back(3);

    adj[1].push_back(3);
    adj[3].push_back(1);
//

    // Call the BFS-based cycle detection
    if (solve1(V, adj)) {
        cout << "Cycle detected using BFS!" << endl;
    } else {
        cout << "No cycle found using BFS." << endl;
    }

    // Call the DFS-based cycle detection
    if (solve2(V, adj)) {
        cout << "Cycle detected using DFS!" << endl;
    } else {
        cout << "No cycle found using DFS." << endl;
    }

    return 0;
}