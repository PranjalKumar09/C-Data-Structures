#include <bits/stdc++.h>
using namespace std;


/*
    Graphs Basic
    ===========
        Like tree ,  graph is non linear data structure

        Wide range Application
            -> Electrical Circuits
            -> Shortest routes
            -> Navigation (Google Maps)


        Types of Graph
        ==============

        1) Null (having no edge)
        2) Trivial (Have only single vertex smallest graph possible)
        3) Undirected
        4) Directed
        5) Connected
        6) Disconnected
        7) Regular (same degree)
        8) Complete
        9) Cycle (degree of vertex 2)
        10) Cyclic (contain atleast 1 cycle)
        11) Directed Acyclic
        12) Bipartite
        13) Weighted


        Action       | Adjacency Matrix | Adjacency List
        ================================|===============
        Adding edge  |      O(1)        | O(1)
        Removing edge|      O(1)        | O(N)
        Initializing |      O(N*N       | O(N)





        pair<u,v>

        Edge Weight-> Number may assigned to edges , like cost of edge ,if not assingned then assume it 1

        Adjoining Matrix: Take space of n^2 , adjacecy list help by taking very less amount of space
        ================
            vector<vector<int>> adj (n+1);

            for (int i = 0 ; i < e ; i++){
                int u , v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
                }
            return 0;

            TC = O(2E)

        Weighted Adjacency Matrix
        =========================

        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u][v] = wt;
        // adj[v][u] = wt; // For Undirected


        vector< pair <int,int> >


        Every tree in Graph, but not all tree are graph
 */


using namespace std;

int main() {
    int n, e; // n = number of nodes, e = number of edges

    // Input the number of nodes and edges
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;

    // Declare an adjacency list to represent the graph
    vector<vector<int>> adj(n + 1);  // Unweighted adjacency list

    // Input edges for unweighted graph
    cout << "Enter the edges (u, v) for unweighted graph:" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph, add both directions
    }

    // Output adjacency list for the unweighted graph
    cout << "Adjacency List (Unweighted):" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ":";
        for (int j : adj[i]) {
            cout << " " << j;
        }
        cout << endl;
    }

    // Weighted adjacency matrix representation
    vector<vector<int>> weightedAdj(n + 1, vector<int>(n + 1, 0));  // Weighted adjacency matrix

    cout << "Enter the edges (u, v, wt) for weighted graph:" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        weightedAdj[u][v] = wt;
        weightedAdj[v][u] = wt;  // For undirected graph, add both directions
    }

    // Output adjacency matrix for the weighted graph
    cout << "Adjacency Matrix (Weighted):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << weightedAdj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}