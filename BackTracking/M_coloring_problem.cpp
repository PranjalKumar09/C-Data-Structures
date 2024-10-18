#include <bits/stdc++.h>
using namespace std;

/* 
M Coloring Problem
==================
    TC - O(N^M)
    SC - O(N)
 */

bool isValid(int node, int color[], vector<vector<int>>& graph, int n, int col) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && color[i] == col) 
            return false;
        
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, int color[], int node, int n) {
    if (node == n) 
        return true;
    

    for (int col = 1; col <= m; col++) {
        if (isValid(node, color, graph, n, col)) {
            color[node] = col;

            if (graphColoringUtil(graph, m, color, node + 1, n)) 
                return true;
            

            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m, int n) {
    int color[n];
    memset(color, 0, sizeof(color));

    if (graphColoringUtil(graph, m, color, 0, n)) {
        cout << "Solution exists: Following are the assigned colors\n";
        for (int i = 0; i < n; i++) 
            cout << "Node " << i << " -> Color " << color[i] << endl;
        
        return true;
    }

    cout << "Solution does not exist";
    return false;
}

int main() {
    int n = 4; 
    int m = 3; 

    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (!graphColoring(graph, m, n)) 
        cout << "No solution found\n";
    

    return 0;
}
