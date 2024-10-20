#include <bits/stdc++.h>
using namespace std;

/* 
N Queen
=======

Placing n queeen on n*n board such that no queen attack each other
    each row    -> 1q
    each column -> 1q



*/

void printing_2d_array(vector<vector<string>> &arr){
    for (int i = 0; i < arr.size(); ++i){
        for (int j = 0; j < arr[i].size(); ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution_1 {
public:
    void solve_util_1(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; ++row) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve_util_1(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<string> &board, int n) {
        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        // Check left side
        for (int j = col; j >= 0; --j) {
            if (board[row][j] == 'Q') return false;
        }

        // Check lower diagonal on left side
        for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    vector<vector<string>> solve(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve_util_1(0, board, ans, n);
        return ans;
    }
};


class Solution_2 {
public:
    void solve_util_2(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal) {
        int n = board.size();
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (!leftRow[row] && !upperDiagonal[row + col] && !lowerDiagonal[row - col + n - 1]) {
                board[row][col] = 'Q';
                leftRow[row] = upperDiagonal[row + col] = lowerDiagonal[row - col + n - 1] = 1;

                solve_util_2(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal);
                
                // Backtrack
                board[row][col] = '.';
                leftRow[row] = upperDiagonal[row + col] = lowerDiagonal[row - col + n - 1] = 0;
            }
        }
    }

    vector<vector<string>> solve(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve_util_2(0, board, ans, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};

int main() {
    int n = 5;  // Example input for the N-Queens problem
    Solution_1 solution1;
    vector<vector<string>> result1 = solution1.solve(n);

    for (const auto &solution1 : result1) {
        for (const auto &row : solution1) {
            cout << row << endl;
        }
        cout << endl;
    }
    
    cout << "========================================================" << endl;
    Solution_2 solution2;
    vector<vector<string>> result2 = solution2.solve(n);

    for (const auto &solution2 : result2) {
        for (const auto &row : solution2) 
            cout << row << endl;
        
        cout << endl;
    }



    return 0;
}
