#include <bits/stdc++.h>
using namespace std;

/*
    Topological Sort by Kahn Algo
    =============================
    by bfs

    TC: O(V+E)
    SCl O(2V)

 */

vector<int> solve(int V, vector<vector<int> > &adj){
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
        for (auto it: adj[i])
            indegree[it]++;
    
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);
    
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it:adj[node]){
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;

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