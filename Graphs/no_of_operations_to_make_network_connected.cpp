#include <bits/stdc++.h>
using namespace std;

/*
    No of operations to make networks connected

    You can remove from anywhere & add anywhere

    

    TC: O(E*4a)
    SC: O(2N)

    4a -> disjoint set operation
    n -> no of node

    2n for array (parent & size)
\
*/

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    // Initialize distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Set distance to self as 0
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    // Populate distances based on edges
    for (const auto &edge : edges)
    {
        int u = edge[0], v = edge[1], weight = edge[2];
        dist[u][v] = weight;
        dist[v][u] = weight; // Bidirectional
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // Count neighbors within the threshold for each city
    int resultCity = -1, minNeighbors = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int neighbors = 0;
        for (int j = 0; j < n; j++)
            if (i != j && dist[i][j] <= distanceThreshold)
                neighbors++;

        // Update the result city
        if (neighbors < minNeighbors || (neighbors == minNeighbors && i > resultCity))
        {
            minNeighbors = neighbors;
            resultCity = i;
        }
    }

    return resultCity;
}

int main()
{
    // Example inputs
    int n = 4; // Number of cities
    int m = 4; // Number of edges
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {2, 3, 4},
        {0, 3, 7}};
    int distanceThreshold = 4;

    // Call the function
    int resultCity = findCity(n, m, edges, distanceThreshold);

    // Output the result
    cout << "The city with the smallest number of neighbors within distance threshold is: " << resultCity << endl;

    return 0;
}
