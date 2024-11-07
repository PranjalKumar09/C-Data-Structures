#include <bits/stdc++.h>
using namespace std;

/*
    Articulation Point
    ==================

    Nodes on which removal graph breaks into multiple components

    i/p: int n, vector<int> adj[]
    o/p: vector<int>

    In this low, not only we excluded parent put also visited node,

    In bridges we checked in DFS, if there exist any  alternative  from adjacent node to current node.
    We cant do we trying ot remove current node along with all edge linked we will check there exist adjacent node not be starting node

    To avoid store of duplication node , we will store nodes in hash away (i.e. mark array used) instead of direct inserting

    if (low(it) > tin[node])   => if low[it] >= tin[node]  &&  parent != -1
    for bridge                                 if articulation point




low[neighbor] >= tin[node]:
    If true, it means that removing node would disconnect neighbor (and its entire subtree) from the rest of the graph, making node an articulation point.

parent != -1:
    The logic here is that a non-root articulation point must satisfy this condition. If we are at a root node, we don't check this condition because the rules for root nodes are different


and we will check the root separately

    TC : o(V+2E)
    SC : O(3V)
    */

void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<int> &articulationPoints, int &timer)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int children = 0;

    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue; // Skip the parent edge

        if (!vis[neighbor])
        { // If neighbor is not visited
            dfs(neighbor, node, vis, adj, tin, low, articulationPoints, timer);
            low[node] = min(low[node], low[neighbor]);

         // Articulation point condition
            if (low[neighbor] >= tin[node] && parent != -1) // parent != -1 for path node
                articulationPoints.push_back(node);
            children++;
        }
        else
        { // Update low value for back edge
            low[node] = min(low[node], tin[neighbor]);
        }
    }

    // If the current node is root of DFS tree and has two or more children
    if (parent == -1 && children > 1)
    {
        articulationPoints.push_back(node);
    }
}

void solve(int n, vector<vector<int>> &adj)
{
    vector<int> vis(n, 0), tin(n), low(n);
    vector<int> articulationPoints;
    int timer = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, adj, tin, low, articulationPoints, timer);
        }
    }

    // Output the articulation points
    cout << "Articulation Points: ";
    for (int point : articulationPoints)
    {
        cout << point << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5; // Number of nodes
    vector<vector<int>> adj(n);

    // Example edges
    adj[0] = {1, 2};
    adj[1] = {0, 2, 3};
    adj[2] = {0, 1};
    adj[3] = {1, 4};
    adj[4] = {3};

    solve(n, adj);
    return 0;
}