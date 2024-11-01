#include <bits/stdc++.h>
using namespace std;

/*
Shortest Path in Directive - Non Cyclic Path
============================================
    by topological sort
    edge wise help to find location of

    i/p: int N, int M , vector<vector<int>> &edges
    o/p: vector<int> dist

    topological sort     adjacent node traversal
    TC: O(N+M) +            O(N+M)

    SC: O(N) + O(N) +   O(N)  +  O(N+M)
    stack     dis   visited   topological sort

*/


vector<int> solve(int N, int M, vector<vector<int>>& edges) {
    // Adjacency list for storing the graph
    vector<vector<pair<int, int>>> adj(N);
    
    // Fill the adjacency list
    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
    }
    
    // Step 1: Compute in-degrees of each node
    vector<int> inDegree(N, 0);
    for (int i = 0; i < N; i++) {
        for (auto& edge : adj[i]) {
            inDegree[edge.first]++;
        }
    }
    
    // Step 2: Perform Kahn’s algorithm for topological sorting
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // Step 3: Find shortest paths from source (assuming source is 0)
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    
    for (int u : topoOrder)
        if (dist[u] != INT_MAX)  // If u is reachable
            for (auto& edge : adj[u]){
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
                }
    
    // Replace unreachable nodes with -1
    for (int i = 0; i < N; i++)
        dist[i] = (dist[i] == INT_MAX) ? -1 : dist[i];
    
    return dist;
}
int main() {
    // Example test case
    int N = 6; // Number of nodes
    int M = 7; // Number of edges
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 3},
        {1, 2, 2},
        {1, 3, 6},
        {2, 3, 7},
        {2, 4, 4},
        {3, 4, 1}
    };
    
    // Call the solve function
    vector<int> distances = solve(N, M, edges);
    
    // Print the result
    cout << "Shortest distances from source node 0:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << ": " 
            << ((distances[i] == -1) ? "Unreachable" : to_string(distances[i])) 
            << endl;
    }
    
    return 0;
}


