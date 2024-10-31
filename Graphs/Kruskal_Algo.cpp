#include <bits/stdc++.h>
using namespace std;

/*
    Kruskal Algo
    ============
    (by use of Disjoint Set data structure)

    i/p: int V, vector<vector<int> > adj[]
    o/p: int sum of weight of edge of MST

    TC => O(N+E) + O(E log E) + O(E)
    SC => O(N) + O(N) + O(E)
        |___________|   |__| array we are storing edge information
        Disjoint Set
    
    if rank used extra O(N) space
    
*/

class DisJointSet1
{ // BY  UNION BY RANK
    vector<int> rank, parent;

public:
    DisJointSet1(int n)
    {
        rank.assign(n, 0);
        parent.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findPar(int node)
    { // if nod
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int parU = findPar(u);
        int parV = findPar(v);

        if (parU == parV)
            return;

        if (rank[parU] < rank[parV])
            parent[parU] = parV;
        else if (rank[parU] > rank[parV])
            parent[parV] = parU;
        else
        {
            parent[parV] = parU;
            rank[parU]++;
        }
    }

};

// Function to find the MST using Kruskal's Algorithm
int solve(vector<vector<pair<int, int>>> &adj, int V)
{
    vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}

    for (int u = 0; u < V; u++) // extracting edge information   TC: O(N+E)
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            edges.push_back({weight, {u, v}});
        }
    

    // Sort edges by weight
    sort(edges.begin(), edges.end()); // minimuum weight first   TC: O(E log E)

    // Initialize the Disjoint Set for V vertices
    DisJointSet1 ds(V);

    int mstWeight = 0;
    vector<pair<int, int>> mstEdges;

    // Kruskal's algorithm
    for (auto it : edges)   // TC: O(E)
    {
        int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;

        // If u and v belong to different sets, include this edge in the MST
        if (ds.findPar(u) != ds.findPar(v)) // only if ultimate parent do nothing
        {
            mstWeight += weight;
            mstEdges.push_back({u, v});
            ds.unionByRank(u, v);
        }
    }

    // Print the MST edges
    cout << "Edges in the MST:\n";
    for (auto edge : mstEdges)
        cout << edge.first << " - " << edge.second << "\n";
    

    return mstWeight;
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // Adding edges (u, v, weight)
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

    int mstWeight = solve(adj, V);
    cout << "Total weight of MST: " << mstWeight << endl;

    return 0;
}