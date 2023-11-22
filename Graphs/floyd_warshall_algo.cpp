#include <bits/stdc++.h>
using namespace std;

/*
Floyd Warshall Algo (Multi Source Shortest)
=> Detected negative cycle path
    Dijkstra & Bellman Ford were single source

    0 -> n-1
    i -> j
    d[i][j] + d[k][j]
    s -> e


    adjacency matrix: i.p: vector<vector<int>> &matrix


    TC: O(V^3)
    SCl: O(V^2)
*/

void solve(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Initialize the distance matrix
    vector<vector<int>> dist = matrix;

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++)
     // Intermediate node
        for (int i = 0; i < n; i++)
         // Start node
            for (int j = 0; j < n; j++)
             // End node
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                
            
        
    

    // Detect negative weight cycles
    for (int i = 0; i < n; i++)
        if (dist[i][i] < 0){
            cout << "Negative weight cycle detected.\n";
            return;}
        
    

    // Print the shortest distance matrix
    cout << "Shortest distances between all pairs of nodes:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    // Predefined adjacency matrix
    vector<vector<int>> matrix = {
        {0, 3, INT_MAX, 5},
        {2, 0, INT_MAX, 4},
        {INT_MAX, 1, 0, INT_MAX},
        {INT_MAX, INT_MAX, 2, 0}};

    solve(matrix);
    // cout <<"w";/
    return 0;
}
