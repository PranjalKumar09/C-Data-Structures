#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        map<int , vector<int> > relation;
        for(auto &edge: edges)
            relation[edge[1]].push_back(edge[0]);
        
        for (int i = 0; i < n; i++){
            dfs(edges, relation);
            
        }
        
    }
};