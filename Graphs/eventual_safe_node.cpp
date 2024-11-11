#include <bits/stdc++.h>
using namespace std;

/*

    Eventual Safe Algo
    ==================
    Node is terminal node if no outgoing edges. Node is safe node if every possible path starting from node leads to terminal node

    i/p : int V, vector<int> adj[]
    o/p : vector<int>

    Overall
        By topological
        Reverse All direction
        Get all Indegree 0
        Indegree, do removal of edges on adjacent nodes

        BFS   for sorting no of safe node
    TC: O(V+E) + O(V+E)
    SC: O(3N) -> Indegree, queue, adjacent
 */

// DFS functions for Kosaraju's Algorithm

vector<int> solve(vector<vector<int>> &adj)
{
    int V = adj.size();            // Number of vertices
    vector<vector<int>> adjRes(V); // Transposed graph
    vector<int> indegree(V, 0);

    // Step 1: Reverse the edges and calculate indegree
    for (int i = 0; i < V; i++)
        for (auto it : adj[i])
        {
            adjRes[it].push_back(i); // Reverse the edge direction
            indegree[i]++;           // Increase the indegree of the original node
        }
    

    // Step 2: Start with nodes having zero indegree (no incoming edges)
    queue<int> q;
    vector<int> safeNodes;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i); // Push nodes with zero indegree into the queue
    

    // Step 3: Perform BFS (topological sort) to find safe nodes
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node); // This node is safe

        for (auto it : adjRes[node]){
            indegree[it]--; // Reduce indegree of the original nodes
            if (indegree[it] == 0)
                q.push(it); // Push nodes with zero indegree into the queue
        }
    }

    // Step 4: Sort the safe nodes before returning (as required by the problem)
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

int main()
{
    // Number of vertices (V) and edges (E)
    int V = 7;

    // Adjacency list for the graph (predefined edges)
    vector<vector<int>> adj = {
        {1, 2}, // Node 0 -> 1, 2
        {2, 3}, // Node 1 -> 2, 3
        {5},    // Node 2 -> 5
        {0},    // Node 3 -> 0
        {5},    // Node 4 -> 5
        {},     // Node 5 (no outgoing edges)
        {4, 5}  // Node 6 -> 4, 5
    };

    // Call the solve function to find eventual safe nodes
    vector<int> safeNodes = solve(adj);

    // Output the eventual safe nodes
    cout << "The eventual safe nodes are: ";
    for (int node : safeNodes)
        cout << node << " ";
    
    cout << endl;

    return 0;
}
