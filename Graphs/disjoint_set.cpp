#include <bits/stdc++.h>
using namespace std;

/*
    DISJOINT SET
    ============

    Components of same component or different
    Components or different

    2 imp operation -> find parent or find set union rank & size: find par()  finding parent
                    -> Union rank & size

    Dynamic Graph-> refers to graph keep changing its configuration

    Rank: distance (no of nodes include leaf node) b/w furthest leaf node & current node


    TC-> O(1)
    Union by rank
    -------------

    Union(1,2) -> ((1 0), (2 0))        (1 1)
                                        /
                                    (2 0)

    Union(2,3) -> ((2 0), (3 0))         (1 1)
                                        /   \
                                    (2 0)  (3 0)

    Union(4,5) -> ((4 0), (5 0))       (4 1)
                                        /
                                    (5 0)

    Union(6,7) -> ((6 0), (7 0))        (6 1)
                                        /
                                    (7 0)

    Union(5,6) -> ((5 0), (6 0))        (4 2)
                                        /    \
                                    (5 0)   (6 1)
                                                \
                                                (7 0)

 */

class DisJointSet1 { // BY  UNION BY RANK
    vector<int> rank , parent;
    public:
        DisJointSet1(int n)
        {
            rank.assign(n, 0);
            parent.assign(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

    int findPar(int node){ // if nod
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    /*
        We are concerned about ultimate parent not imidate parent because at larger structure immediate way be different but ultimate parent might be same
        Now this find UPare takes more time  collision to constant TC by path compression method

        Connect each node particular to ultimate parent by this we will not need to traverse all the way also there as no change in rank while applying it.    [less depth]

        1            1
        |    ==>   / | \
        2         2  3  4
        |
        3
        |
        4

    */
    void unionByRank (int u , int v){
        int parU = findPar(u);
        int parV = findPar(v);

        if(parU == parV) return;

        if(rank[parU] < rank[parV])
            parent[parU] = parV;
        else if(rank[parU] > rank[parV])
            parent[parV] = parU;
        else{   // parent of smaller rank = larger rank, if both equal then do in any one
            parent[parV] = parU;
            rank[parU]++;
        }
    }

    // We done smaller rank to larger rank, it should shrink hieght of graph reduce TC as much as we can
    // Union by Rank
};


class DisjointSet2 { // BY  UNION BY SIZE
    vector<int> parent, size;
    public:
    DisjointSet2(int n){
        parent.assign(n, 0);
        size.assign(n, 1);
        for(int i = 0 ; i < n ; i++)
            parent[i] = i;
    }

    int findPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize (int u, int v){
        int parU = findPar(u);
        int parV = findPar(v);

        if(parU == parV) return;

        if(size[parU] < size[parV]){
            parent[parU] = parV;
            size[parV] += size[parU];
            }
        else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
};

int main()
{
    int n = 7; // Number of elements (0 to 6)

    // Union by Rank example
    DisJointSet1 ds1(n);
    ds1.unionByRank(0, 1);
    ds1.unionByRank(1, 2);
    ds1.unionByRank(3, 4);
    ds1.unionByRank(5, 6);
    ds1.unionByRank(4, 5);

    cout << "Find using Union by Rank:" << endl;
    cout << "Parent of 2: " << ds1.findPar(2) << endl;
    cout << "Parent of 6: " << ds1.findPar(6) << endl;

    // Union by Size example
    DisjointSet2 ds2(n);
    ds2.unionBySize(0, 1);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(3, 4);
    ds2.unionBySize(5, 6);
    ds2.unionBySize(4, 5);

    cout << "Find using Union by Size:" << endl;
    cout << "Parent of 2: " << ds2.findPar(2) << endl;
    cout << "Parent of 6: " << ds2.findPar(6) << endl;

    return 0;
}