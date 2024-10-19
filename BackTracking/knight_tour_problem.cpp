#include <bits/stdc++.h>
using namespace std;

/* 
The Knight Tour Problem
======================= 
    Knight tour entire board(then it will taje around (n*n)-1 moves by DFS)
        (i-2)(j-1)      (i-2)(j+1)

    (i-1)(j-2)                  (i-1)(j+2)
                    *
    (i+1)(j-2)                  (i+1)(j+2)

        (i+2)(j-1)      (i+2)(j+1)


    TC: 0(8^(n^2))

    note this take lot  of time means lot of time
 */


void solve_util(int n, int i, int j, int cnt, vector<vector<int>>& mat, vector<vector<bool>> &visited, bool& solved) {
    if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j]) return;

    // cout << cnt << endl;
    mat[i][j] = cnt;
    visited[i][j] = true;
    if (cnt == n * n - 1 ) {
        solved = true;
        return;
    }

    // Possible moves for a knight
    int moves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                       {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    
    for (int k = 0; k < 8; k++) {
        solve_util(n, i + moves[k][0], j + moves[k][1], cnt + 1, mat, visited, solved);
        if (solved) return;
    }
    visited[i][j] = false;
    mat[i][j] = 0;
}

void solve(int n) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    bool solved = false;
    
    solve_util(n, 0, 0, 0, mat, visited, solved);

    if (solved) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "Solution does not exist." << endl;
    }
}

int main() {
    int n = 8; // Change the board size as needed
    solve(n);
    return 0;
}

