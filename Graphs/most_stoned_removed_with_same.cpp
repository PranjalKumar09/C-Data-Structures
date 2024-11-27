#include <bits/stdc++.h>
using namespace std;
/*
Most stoned removed with same Row or Column
    You can remove stone if it shares row or column with other Stones

    TC: O(V^3)
    SC: O(V^2)
 */
class DisjointSet
{
public:
    vector<int> parent, rank;

    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (parent[node] != node)
        {
            parent[node] = find(parent[node]); // Path compression
        }
        return parent[node];
    }

    void unite(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

void solve(vector<vector<int>> &stones)
{
    // Step 1: Initialize the DSU with a size that covers rows and columns
    int maxRow = 0, maxCol = 0;
    for (auto &stone : stones)
    {
        maxRow = max(maxRow, stone[0]);
        maxCol = max(maxCol, stone[1]);
    }
    // Using an arbitrary offset to map columns distinct from rows
    int offset = maxRow + 1;
    DisjointSet ds(maxRow + maxCol + 2);

    // Step 2: Map each stone's row and column to DSU
    for (auto &stone : stones)
    {
        int row = stone[0];
        int col = stone[1] + offset; // Offset to differentiate rows and columns
        ds.unite(row, col);
    }

    // Step 3: Count unique components (connected components in DSU)
    unordered_set<int> uniqueComponents;
    for (auto &stone : stones)
    {
        int row = stone[0];
        int col = stone[1] + offset;
        uniqueComponents.insert(ds.find(row));
        uniqueComponents.insert(ds.find(col));
    }

    // Step 4: Calculate the result
    int numStones = stones.size();
    int numComponents = uniqueComponents.size();
    int stonesRemoved = numStones - numComponents;

    cout << "Maximum stones that can be removed: " << stonesRemoved << endl;
}/* 
This question similar to island question,
    c1 component:    component c2:    component c3:
        n1 - 1,         n2 - 1           n3 - 1

        total => n1 + n2 + n3 - 3 => n - c


 */

int main(){
    
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    solve(stones); // Output: Maximum stones that can be removed: 5
    return 0;
    
}