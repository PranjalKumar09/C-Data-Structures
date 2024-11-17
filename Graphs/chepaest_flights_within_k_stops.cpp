#include<bits/stdc++.h>
using namespace std;

/* 
    Cheapest Flights within  K stops cost also given end point & starting point not considered as stops


    (simple dijkstra dont wroke here)

    first priority of judgement will stops

    1) Create directed adjacency list
    2) Queue pair <int ,  pair <int , int> >
    3) Push {0, <src, 0>} in initialise dist (n, 1e9)
    4) Start while loop
    
    TC = O(N)
    SC = O(E+M)
    Adjacency
 */
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    // Create the adjacency list
    vector<pair<int, int>> adj[n];
    for (auto flight : flights)
        adj[flight[0]].push_back({flight[1], flight[2]}); // {destination, price}

    // Priority queue: <cost, <current_node, stops>>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    // Distance array to track the minimum cost to reach each node
    vector<int> dist(n, INT_MAX);

    // Push the starting point into the priority queue
    pq.push({0, {src, 0}}); // {cost, {node, stops}}
    dist[src] = 0;

    while (!pq.empty()) {
        auto [cost, state] = pq.top();
        auto [node, stops] = state;
        pq.pop();

        // If destination is reached, return the cost
        if (node == dst)
            return cost;

        // If stops exceed K, skip further exploration
        if (stops > K)
            continue;

        // Explore neighbors
        for (auto [neighbor, price] : adj[node])
        {
            int newCost = cost + price;

            // If a cheaper cost is found or if it's within stop constraints
            if (newCost < dist[neighbor])
            {
                dist[neighbor] = newCost;
                pq.push({newCost, {neighbor, stops + 1}});
            }
        }
    }

    // If destination is unreachable, return -1
    return -1;
}

// Driver function
int main()
{
    int n = 4; // Number of cities
    vector<vector<int>> flights = {
        {0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 2, 500}};
    int src = 0, dst = 3, K = 1;

    int result = findCheapestPrice(n, flights, src, dst, K);
    if (result != -1)
        cout << "Cheapest Price: " << result << endl;
    else
        cout << "No valid route within K stops." << endl;

    return 0;
}