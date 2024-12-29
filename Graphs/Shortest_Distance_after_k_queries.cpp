#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
 * Problem Statement:
 * -------------------
 * You are given a graph with `n` nodes numbered from `0` to `n-1`. Initially,
 * the graph is a simple path where each node `i` is connected to node `i+1`.
 *
 * You are also given a list of queries where each query represents the addition of
 * a new road between two nodes `u` and `v`. After adding each road, calculate the
 * shortest path from node `0` to node `n-1`.
 *
 * Return a list of integers where each integer is the shortest path after adding
 * the corresponding road.
 *
 *
 * Example Input:
 * n = 5
 * queries = [[0, 2], [1, 3], [2, 4]]
 *
 * Output:
 * [3, 3, 2]
 */

// BFS to find the shortest path from start to end
int bfs(int start, int end, int n, const vector<vector<int>> &graph)
{
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int u : graph[curr])
        {
            if (dist[u] > dist[curr] + 1)
            {
                dist[u] = dist[curr] + 1;
                q.push(u);
            }
        }
    }

    return dist[end];
}

// Main function to process queries and return results
vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
{
    vector<int> answer;
    vector<vector<int>> graph(n);

    // Build initial graph (simple path)
    for (int i = 0; i < n - 1; i++)
    {
        graph[i].push_back(i + 1);
    }

    // Process each query
    for (auto query : queries)
    {
        int u = query[0], v = query[1];
        graph[u].push_back(v);                     // Add new road
        answer.push_back(bfs(0, n - 1, n, graph)); // Compute shortest path
    }

    return answer;
}

int main()
{
    // Example Input
    int n = 5;
    vector<vector<int>> queries = {{0, 2}, {1, 3}, {2, 4}};

    // Solve the problem
    vector<int> result = shortestDistanceAfterQueries(n, queries);

    // Output the result
    for (int dist : result)
    {
        cout << dist << " ";
    }

    return 0;
}
