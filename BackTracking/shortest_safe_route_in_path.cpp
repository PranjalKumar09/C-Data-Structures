#include <bits/stdc++.h>
using namespace std;


/* 
Find shortest safe route in path with landmine
==============================================

    Landmine represents by 0

    adjacent -> bottom, right, left, right

    TC =  O(R*C)
    SC =  O(R*C)
 */

class Solution {
    int R, C;
    vector<int> rowNum = {-1, 0, 0, 1};
    vector<int> colNum = {0, 1, -1, 0};
    
public:
    bool isSafe(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int x, int y) {
        return (matrix[x][y] == 1 && !visited[x][y]);
    }

    bool isValid(int x, int y) {
        return (x < R && y < C && x >= 0 && y >= 0);
    }

    void markUnsafe(vector<vector<int>> &matrix) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int newX = i + rowNum[k];
                        int newY = j + colNum[k];
                        if (isValid(newX, newY) && matrix[newX][newY]) {
                            matrix[newX][newY] = -1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void solveUtil(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int &min_dist, int dist) {
        if (j == C -1) {
            min_dist = min(min_dist, dist);
            return;
        }
        
        if (dist >= min_dist) 
            return;

        visited[i][j] = true;
        
        for (int k = 0; k < 4; k++) {
            int newX = i + rowNum[k];
            int newY = j + colNum[k];
            if (isValid(newX, newY) && isSafe(matrix, visited, newX, newY)) {
                solveUtil(matrix, visited, newX, newY, min_dist, dist + 1);
            }
        }

        visited[i][j] = false; // backtracking
    }

    void solve(vector<vector<int>> &matrix) {
        R = matrix.size();
        C = matrix[0].size();
        int min_dist = INT_MAX;
        markUnsafe(matrix);
        // for (int i = 0; i < R; i++) {
        //     for (int j = 0; j < C; j++) 
        //         cout << matrix[i][j] << " " ;
        //     cout << endl;}

        vector<vector<bool>> visited(R, vector<bool>(C, false));

        for (int i = 0; i < R; i++) {
            if (matrix[i][0] == 1) {
                solveUtil(matrix, visited, i, 0, min_dist, 0);
                if (min_dist == C - 1) break;
            }
        }

        if (min_dist == INT_MAX) 
            cout << "Not found";
        else 
            cout << "Shortest safe route length is: " << min_dist+1 << endl;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 0, 1}
    };
    
    Solution obj;
    obj.solve(matrix);
    return 0;
}