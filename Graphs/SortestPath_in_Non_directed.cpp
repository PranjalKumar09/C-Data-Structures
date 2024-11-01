#include <bits/stdc++.h>
using namespace std;

/*
Shortest Path in Non - Directive
================================
    i/p : vector <vector <int >> & edges , int N, int M, int src
    o/p : vector <int>

    TC => O(N+2M) + O(M) + O(M)   [BFS]
    SC => O(N+2M) + O(M) + O(N)
    Adjacency list
 */

vector <int> solve(vector <vector <int >> & edges , int N, int M, int src){
    vector<vector <int >> adj(N);
    for (auto it: edges){
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N, INT_MAX);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for (auto it: adj[node])
            if (dist[node]+1 < dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
    }
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++)
        if (dist[i]!= INT_MAX) ans[i] = dist[i];
    return ans;
    
}
int main() {
    // Example graph
    int N = 6;
    int M = 7;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3},
        {2, 4}, {3, 4}, {4, 5}
    };
    int src = 0;  // Source node

    // Compute shortest paths
    vector<int> distances = solve(edges, N, M, src);

    // Print distances
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        if (distances[i] == -1)
            cout << "Node " << i << " is not reachable from node " << src << "\n";
        else
            cout << "Node " << i << ": " << distances[i] << "\n";
        
    }

    return 0;
}