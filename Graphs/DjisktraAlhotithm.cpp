#include <bits/stdc++.h>
using namespace std;

/*


    Dijkstra Algorithm
    ==================
        TC: O(E log V]
            E -> Total no of edges
            V -> Total number of nodes

            O(V* (log (Heap Size) + no-of-left-ver))
            => O(V* (log (Heap Size) + (V-1) * log (Heap Size))
            => O(V* V * log (Heap Size)
            => O(V^2 * log (Heap Size) // at max V^2 at worst when all pushed
            => O(E log (V^2))
            => O(2*E log (V^2))   // 
            Worst case

        SC:O(E+V))


    Why we get answer even in Queue so why PQ?
    In many condition Queue take more time which perform on every paths. Unnecessary exploration of paths unnecessary  iteration


    Only difference b/w using PQ & set is we ca check if exists pair with same node, but greater distance than current inserted noded as there no point in keeping that int keeping that int set. So we simply delete element with greater distance for same node

    Djisktra Algo not works in => * Negative Weight   * Negative cycle



 */

vector<int> solve(int V, int s, vector<vector<pair<int, int>>> &adj) {
    set<pair<int, int>> st;
    vector<int> dist(V, INT_MAX);

    dist[s] = 0;
    st.insert({0, s});

    while (!st.empty()) {
        auto top = *st.begin();
        int node = top.second;
        int dis = top.first;

        st.erase(top);

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dis + edgeWeight < dist[adjNode]) {
                if (dist[adjNode] != INT_MAX)
                st.erase({dist[adjNode], adjNode});
                
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        
        }
    }
    return dist;
}


vector<int> solve2(int V, int s, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, INT_MAX); 
    
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto top = pq.top();
        int node = top.second;
        int dis = top.first;

        pq.pop();
        
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode}); // Push the updated distance and node
            }
        }
    }
    return dist;
}


int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // Adjacency list representing the graph
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    int source = 0;

    cout << "Dijkstra using Set:\n";
    vector<int> distances1 = solve(V, source, adj);
    for (int i = 0; i < V; i++) {
        if (distances1[i] == INT_MAX)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << distances1[i] << "\n";
    }

    cout << "\nDijkstra using Priority Queue:\n";
    vector<int> distances2 = solve2(V, source, adj);
    for (int i = 0; i < V; i++) {
        if (distances2[i] == INT_MAX)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << distances2[i] << "\n";
    }

    return 0;
}