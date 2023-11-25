#include <bits/stdc++.h>
using namespace std;

/*
    Number of ways to arrive at destination in a bidirectional weighted graph
    given integer n. We have to return how many ways you can travel from
    intersection 0 to n-1 in the shortest amount of time using Dijkstra's algorithm.


    TC: O(E*log(n))
    SC: O(N)
*/
void solve(int n, vector<vector<int>> &roads)
{
    vector<pair<int, int>> adj[n];

    // Build adjacency list
    for (auto it : roads)
    {
        int u = it[0], v = it[1], weight = it[2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // Priority queue for Dijkstra's algorithm: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance and ways vectors
    vector<int> dist(n, INT_MAX), ways(n, 0);

    // Initialize for the starting node
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0}); // {distance, node}

    const int MOD = 1e9 + 7;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dis > dist[node])
            continue; // Ignore outdated entries

        // Traverse neighbors
        for (auto &neighbor : adj[node])
        {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            // Relaxation step
            if (dis + edgeWeight < dist[nextNode])
            {
                dist[nextNode] = dis + edgeWeight;
                ways[nextNode] = ways[node]; // Carry over the ways
                pq.push({dist[nextNode], nextNode});
            }
            else if (dis + edgeWeight == dist[nextNode])
            {
                ways[nextNode] = (ways[nextNode] + ways[node]) % MOD; // Add ways
            }
        }
    }

                                            cout << ways[n - 1] << endl ;
}

// Driver function
int main()
{
    // Predefined input
    int n = 7; // Number of nodes
    vector<vector<int>> roads = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 3, 7},
        {2, 3, 1},
        {2, 5, 3},
        {3, 4, 2},
        {4, 6, 1},
        {5, 6, 5}};

    // Solve the problem
    solve(n, roads);

    return 0;
}
