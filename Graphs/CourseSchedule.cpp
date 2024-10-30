#include <bits/stdc++.h>
using namespace std;

/*
    Course Schedule
    ----------------
    TC: O(V+E)
    SC: O(2N)
    
    Perquisite Task  |  Task
    1                | 0
    2                | 1
    3                | 2

    There should be no cyclic dependency by using Topological Sort

 */


bool solve(int V, vector<pair<int,int>> &PreRequisite){
    vector<vector<int>> adj(V); // Edit 1
    for(auto it: PreRequisite)
        adj[it.first].push_back(it.second);
        
    // Rest topologicalSort

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
    return count == V; // Edit 2   if order asked return topo by checking topo.size() == V
    }
int main(){
    vector<pair<int,int>> PreRequisite = {
        {1,0},
        {2,1},
        {3,2}
        ,{0,3} // for checking
    };
    cout << solve(4,PreRequisite);
    
}