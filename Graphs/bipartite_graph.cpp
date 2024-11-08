#include <bits/stdc++.h>
using namespace std;

/*
    Bipartite Graph
    ===============

    if we able to colour graph 2 colour such that no two adjacent have same colour

    Any linear graph with no cycle is always bipartite graph

    TC : o(V+2E)
    SC : O(3V)
    */

bool dfs(int node, int col, vector<int> &colour, vector<vector<int>> &adj)
{
    colour[node] = col; // Assign the current node a colour

    for (auto it : adj[node]){
        if (colour[it] == -1) // If the neighbour has not been visited
            if (!dfs(it, 1 - col, colour, adj)) // Try coloring with opposite color
                return false;                   // If dfs fails, graph is not bipartite
        else if (colour[it] == col) // If the neighbour has the same color
            return false; // Graph is not bipartite
    }
    return true;
}

// Function to solve the bipartite check
bool solve(int V, vector<vector<int>> &adj){
    vector<int> colour(V, -1); // -1 means uncolored

    for (int node = 0; node < V; node++)
        if (colour[node] == -1) // If node is unvisited
            if (!dfs(node, 0, colour, adj)) // Start DFS with color 0
                return false;               // If DFS fails, graph is not bipartite

    return true; // Graph is bipartite
}

// Main function for input and output
int main()
{
    int V = 4; // Number of vertices
    vector<vector<int>> adj(V);

    // Manually setting up the adjacency list
    adj[0] = {1, 3}; // Node 0 is connected to nodes 1 and 3
    adj[1] = {0, 2}; // Node 1 is connected to nodes 0 and 2
    adj[2] = {1, 3}; // Node 2 is connected to nodes 1 and 3
    adj[3] = {0, 2}; // Node 3 is connected to nodes 0 and 2

    if (solve(V, adj))
        cout << "The graph is bipartite." << endl;
    else
        cout << "The graph is not bipartite." << endl;

    return 0;
}