#include <bits/stdc++.h>
using namespace std;

/*
    Topological Sort
    ================

    in DAG

    TC = O(V+E) + O(V)
    SC = O(2N) + O(N)

 */
void dfs(int node, vector<int>& vis,stack<int> & st, vector<vector<int>>& adj) {
    vis[node] = 1;
    for (auto v : adj[node])
        if (!vis[v])
            dfs(v, vis, st, adj);
    st.push(node);
}

vector<int> solve(int &V, vector<vector<int>> &adj){
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i, vis, st, adj);

    vector<int> res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}


int main() {
    int V = 6;

    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topologicalOrder = solve(V, adj);

    cout << "Topological Order of the graph:" << endl;
    for (int node : topologicalOrder)
        cout << node << " ";
    
    cout << endl;

    return 0;
}

