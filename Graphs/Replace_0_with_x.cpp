#include <bits/stdc++.h>
using namespace std;

/*
Replace 0s with 1s that surrounded by Xs
========================================
    i/p
    x x x x
    x 0 x x
    x 0 0 x
    x 0 x x
    x x x 0

    o/p
    x x x x
    x x x x
    x x x x
    x x x x
    x x x 0

    set of x connected to boundary can't be connected
    (by dfs)
    x 0 x x
    x 0 x x
    x 0 0 x
    x 0 x x
    x x x 0


    TC: o(N) + O(N) + O(N*M*4)
    SC: O(N*M)


 */

void dfs(int row, int col, vector<vector<bool> > & vis, vector<vector<char> > & mat, vector<int> &delRow, vector<int> & delCol){
    vis[row][col]=1;
    int n =mat.size(), m = mat[0].size();

    for (int i = 0; i < 4 ; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && nrow < mat.size() && ncol >= 0 && ncol < mat[0].size() && !vis[nrow][ncol] && mat[nrow][ncol]=='0')
dfs(nrow, ncol, vis, mat , delRow, delCol);
    }
}
vector<vector<char> > solve(vector<vector<char> > &mat){
    int n = mat.size(), m = mat[0].size();
    vector<vector<bool> > vis(n, vector<bool>(m,0));
    vector<int> delRow = {1,-1,0,0}, delCol = {0,0,1,-1};

    for (int i = 0; i < m ; i++){
        if (!vis[0][i] && mat[0][i]=='0') dfs(0, i, vis, mat, delRow, delCol);
        if (!vis[n-1][i] && mat[n-1][i]=='0') dfs(n-1, i, vis, mat, delRow, delCol);
    }
    for (int i = 1; i < n-1 ; i++){
        if (!vis[i][0] && mat[i][0]=='0') dfs(i,0, vis, mat, delRow, delCol);
        if (!vis[m-1][i] && mat[m-1][i]=='0') dfs(i, m-1,  vis, mat, delRow, delCol);
    }

    for (int i = 0 ; i < n; i++)
        for (int j = 0 ; j < m ; j++)
            if (!vis[i][j] && mat[i][j]=='0')
                mat[i][j] = 'x';
    return mat;
}

int main(){
    vector <vector<char> > mat = {
    {'x', 'x', 'x', 'x'},
    {'x', '0', 'x', 'x'},
    {'0', '0', '0', 'x'},
    {'x', '0', 'x', 'x'},
    {'x', 'x', 'x', '0'} };

    vector <vector<char> > mat2 = solve (mat);
    for (int i  = 0 ; i < mat2.size(); i++) {
        for (int j = 0 ; j < mat2[0].size() ; j++)
            cout<<mat[i][j]<<' ';
        cout << endl;
    }


    return 0;
}