#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        vector<vector<pair<int,pair<int,int>>>> g(V);
        for(auto &e:edges){
            g[e[0]].push_back({e[1],{e[2],e[3]}});
            g[e[1]].push_back({e[0],{e[2],e[3]}});
        }
        vector<vector<int>> d(V,vector<int>(2,1e9));
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>> pq;
        d[a][0]=0;

        /*  d[u][c] = shortest distance to node u

c = 0: haven't used curved edge yet

c = 1: already used one curved edge


d[a][0] = 0;  // Start at node 'a' with 0 curved edges used
pq.push({0, a, 0});  // {distance, node, curved_used}

*/
        pq.push({0,a,0});
        while(!pq.empty()){
            auto[dist,u,c]=pq.top();pq.pop();
            if(dist>d[u][c])continue;
            for(auto[v,w]:g[u]){
                if(d[v][c]>dist+w.first){
                    d[v][c]=dist+w.first;
                    pq.push({d[v][c],v,c});
                }
                if(!c&&d[v][1]>dist+w.second){
                    d[v][1]=dist+w.second;
                    pq.push({d[v][1],v,1});
                }
            }
        }
        int res=min(d[b][0],d[b][1]);
        return res>=1e9?-1:res;
    }
};

int main(){

    return 0;
}