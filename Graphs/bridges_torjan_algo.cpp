#include <bits/stdc++.h>
using namespace std;

/*
    Bridge (Torjan's Algo)
    =========================
    edges when remove graph disconnect
        * A critical connection
        * Divide graph into or more components

    We hae to return all critical connection in any order
    Time of insertion: time when node visited, is called its time of insertion. To store it we can use time array

    Lowest TCL current node refer to all its adjacent node except parent & takes minimum lowest time of insertion

    TC: O(V+2E)
    SC: O(3V) + O(V+2E) {adjacent list, queue, visited array}

 */



void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges, int &timer)
{
    /*
    tin (time of insertion): A vector storing the discovery time of each node during the DFS traversal. tin[node] is the time at which node node was first visited

    low: A vector that tracks the lowest discovery time reachable from the current node (including itself and its descendants). low[node] helps in determining if a node's connection to its parent can be bypassed through its descendants
    
     */
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue; // Skip the edge to the parent

        if (!vis[neighbor])
        {


            // Call DFS on the neighbor
            dfs(neighbor, node, vis, adj, tin, low, bridges, timer);

            // Update the low time of the current node
            low[node] = min(low [node], low[neighbor]);

            // Check if the edge (node, neighbor) is a bridge
            if (low[neighbor] > tin[node])
                bridges.push_back({node, neighbor});
            
        }
        else
            low[node] = min(low[node], tin[neighbor]);
        
    }
}

vector<vector<int>> solve(int V, vector<vector<int>> &adj)
{
    vector<vector<int>> bridges;
    vector<int> tin(V, -1), low(V, -1), visited(V, 0);
    int timer = 0;

    // Call DFS for all components
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, -1, visited, adj, tin, low, bridges, timer);
        
    

    return bridges;
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    // Add edges (this graph is undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // Find bridges
    vector<vector<int>> bridges = solve(V, adj);

    // Print the bridges
    cout << "Bridges are:\n";
    for (auto bridge : bridges)
    {
        cout << bridge[0] << " -- " << bridge[1] << endl;
    }

    return 0;
}
