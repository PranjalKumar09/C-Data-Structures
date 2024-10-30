#include <bits/stdc++.h>
using namespace std;

/*
    Bellman Ford Algo
    ================
    If graph contains negative edge or negative cycle, this algo helps

    Negative graph: If sum of all weight becomes negative

    Only applicable for graph directed graphs
        To do in undirected convert it in directed, * -- *, * <--> *

    In graph of N nodes, it will take at most N-1 edges to reach from first to last node, we need exact N-1 iteration its impossible to draw graph takes more take N-1 edges to reach any node

    To detect negative cycle,
    The path weight decrease in every iteration. WE should have minimized distance within n-1 iteration. Then we will relax edges one more completion of N-1 iteration & if it found further edge found this is negative cycle


    vector<int> dist (V, 1e8); initalized with infinity except source

    TC: O(V*E)
    SC: O(V) -> Distance or array

 */

vector<int> bellmanFord(int V, int E, vector<vector<int>> &edges, int src)
{
    // Initialize the distance from source to all other vertices as infinity (1e8 in this case)
    vector<int> dist(V, 1e8);

    // Distance to the source itself is 0
    dist[src] = 0;

    // Relax all edges (V-1) times
    for (int i = 0; i < V - 1; i++)
        for (int j = 0; j < E; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            // Relaxation step: check if the distance can be minimized
            if (dist[u] != 1e8 && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    

    // Check for negative weight cycles
    for (int j = 0; j < E; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        // If we can still relax the edges, then a negative weight cycle exists
        if (dist[u] != 1e8 && dist[u] + weight < dist[v])
        {
            cout << "Graph contains a negative weight cycle!" << endl;
            return {}; // Return an empty vector to indicate a cycle exists
        }
    }

    return dist; // Return the distance array
}

int main()
{
    int V = 5; // Number of vertices
    int E = 8; // Number of edges

    // Edges: u, v, weight
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    int source = 0; // Starting node

    // Run Bellman-Ford algorithm
    vector<int> distances = bellmanFord(V, E, edges, source);

    if (!distances.empty())
    {
        cout << "Vertex\tDistance from Source\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << "\t" << distances[i] << endl;
        }
    }

    return 0;
}