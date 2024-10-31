#include <bits/stdc++.h>
using namespace std;

/*
    MST -> Kruskla Algo
        -> Prism Algo

    Prism Algo => To find MST or weight of MST
    ==========

    Spanning Tree   -> is tree have V node & V - 1 edges reachable from each other
                    -> Among all spanning tree, one with minimum weight known as minimum spanning tree


    if MST asked edge information stored in form {u,v}   u -> starting node, v -> ending node

    MST array   (if we store edge information as pair of starting & ending nodes)

    insitution is Greedy

    TC -> O(E log E) + O(E log E) => TC = O(2 E log E)
    SC -> O(E) + O(V)

    worst in Graph like star node, in MST we need extra O(V-1) to store edges

 */

int solve(int V, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

    vector<bool> vis(V, 0);
    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node])
            continue;
        vis[node] = true;
        sum += wt;

        for (auto &neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int edw = neighbor.second;

            if (!vis[adjNode])
                pq.push({edw, adjNode});
        }
    }
    return sum;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Hardcoded edges with weights
    // Format: {node, weight}
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    // Perform the calculation without input
    int mst_weight = solve(V, adj);
    cout << "Minimum Spanning Tree weight: " << mst_weight << endl;

    return 0;
}
