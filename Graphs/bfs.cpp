#include <bits/stdc++.h>
using namespace std;

/*
    BFS (breadth-first search)
    =========================
    Like level order traversal

    i/p: int V, vector<int> adj

    Using queue (FIFO)

    TC: o(N+2E)
    SC: o(3N) {adjacent list, queue, visited array}

 */


vector<int> solve(int V, vector<vector<int> >& adj) {
    vector<bool> visited(V, false);
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                ans.push_back(u);  // Add the node to the result vector

                for (auto v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
    // Example usage:
    int V = 5;
    vector<vector<int>> adj = {
        {1, 2},  // Adjacency list for vertex 0
        {0, 3},  // Adjacency list for vertex 1
        {0, 3},  // Adjacency list for vertex 2
        {1, 2, 4},  // Adjacency list for vertex 3
        {3}    // Adjacency list for vertex 4
    };

    vector<int> result = solve(V, adj);

    // Print the BFS traversal order
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}