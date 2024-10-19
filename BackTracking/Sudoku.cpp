#include <bits/stdc++.h>
using namespace std;

/* 
Sudoku Solver
============= 

    TC : O(9^(n^2))
    SC : O(1)

*/
bool isValid(vector<vector<int>> &board, int row, int col, int c) {
    // Check row
    for (int i = 0; i < 9; i++)
        if (board[row][i] == c) return false;

    // Check column
    for (int i = 0; i < 9; i++)
        if (board[i][col] == c) return false;

    // Check 3x3 box
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;
    for (int i = boxRowStart; i < boxRowStart + 3; i++)
        for (int j = boxColStart; j < boxColStart + 3; j++)
            if (board[i][j] == c) return false;

    return true;
}

bool solveSudoku(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 0) {  // Empty cell
                for (int c = 1; c <= 9; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board)) {
                            return true;
                        } else {
                            board[i][j] = 0;  // Backtrack
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(const vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)) {
        cout << "Solved Sudoku board:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists for the given Sudoku board." << endl;
    }

    return 0;
}
