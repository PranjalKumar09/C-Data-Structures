#include <bits/stdc++.h>
using namespace std;

/*
    Kosarajau Algo
    ==============
    Find no of strongly connected component

    Strongly connected component every possible pair inside component is reachable

    We will do from DFS

    i/p : int V, vector<int> adj[]
    o/p : int

        DFS     Reverse   DFS
    TC: O(V+E) + O(V+E) + O(V+E)
    SC: O(V) + O(V) + O(V+E)
        vis   stack  adjacent array

 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// DFS functions for Kosaraju's Algorithm
void dfs1(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            dfs1(it, vis, adj, st);
    st.push(node);
}

void dfs3(int node, vector<int> &vis, vector<int> adjT[])
{
    vis[node] = 1;
    for (auto it : adjT[node])
        if (!vis[it])
            dfs3(it, vis, adjT);
}

int solve(int v, vector<int> adj[])
{
    vector<int> vis(v, 0);
    stack<int> st;

    // Step 1: Perform DFS to get the nodes in topological order
    for (int i = 0; i < v; i++)
        if (!vis[i])
            dfs1(i, vis, adj, st);

    // Step 2: Transpose the graph
    vector<int> adjT[v];
    for (int i = 0; i < v; i++)
        for (auto it : adj[i])
            adjT[it].push_back(i);

    // Step 3: Perform DFS on transposed graph in topological order
    for (int i = 0; i < v; i++)
        vis[i] = 0;
    int scc = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            dfs3(node, vis, adjT);
            scc++;
        }
    }

    return scc;
}

int main()
{
    int v = 5; // Predefined number of vertices
    vector<int> adj[v];

    // Predefined edges for a sample graph
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);
    adj[1].push_back(0);
    adj[1].push_back(2);

    // Call the solve function and output the number of SCCs
    int sccCount = solve(v, adj);
    cout << "The number of Strongly Connected Components (SCCs): " << sccCount << endl;

    return 0;
}


