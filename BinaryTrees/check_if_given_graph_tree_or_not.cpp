#include <bits/stdc++.h>
using namespace std;

/* 
Check if given graph is Tree or Not
===================================
"Every Tree is Graph, but every graph is not a Tree"
No Cycle , And connected 
 */


bool IsCyclic(int src, int prt, vector<vector<int>> &Vec, vector<bool> &visited) {
    cout << "hello" << endl;
    visited[src] = true;

    for (auto i : Vec[src]) {
        if (!visited[i]) {
            if (IsCyclic(i, src, Vec, visited)) return true; // Corrected recursive call
        } else if (i != prt) {
            return true; // Found a cycle
        }
    }
    return false;
}


bool solve(int n, vector<vector<int>> &Vec) {
    vector<bool> visited(n, false);
    // Check for cycle starting from node 0, assuming the graph is 0-indexed
    if (IsCyclic(0, -1, Vec, visited)) return false;
    // Check if all nodes are visited to ensure the graph is connected
    for (int i = 0; i < n; i++) 
        if (!visited[i]) return false;
    
    return true;
}

int main() {
    int n = 5; // Number of nodes
    int m = 4; // Number of edges

    vector<vector<int>> Vec(n);

    // Predefined edges for the graph
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 4}
    };

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        Vec[u].push_back(v);
        Vec[v].push_back(u);
    }
    if (solve(n, Vec)) {
        cout << "The graph is a tree." << endl;
    } else {
        cout << "The graph is not a tree." << endl;
    }
    
    return 0;
}
