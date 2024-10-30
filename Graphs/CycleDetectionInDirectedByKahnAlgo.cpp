#include <bits/stdc++.h>
using namespace std;

/*
Cycle Detection in Directed by Kahn Algo
========================================

    just apply topological -> not appliable on cyclic
                bfs
 */


bool solve(int V, vector<vector<int> > &adj){
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
        for (auto it: adj[i])
            indegree[it]++;
    
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);
    
    // vector<int> topo;
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // topo.push_back(node);
        count++;

        for (auto it:adj[node]){
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return count != V;
    }
int main(){
    vector<vector<int>> adj = {
        {1},
        {2},
        {3},
        {4},
        {
         0 // This edge creates a cycle
        }
    };
    cout << solve(adj.size(), adj) << endl;


}

