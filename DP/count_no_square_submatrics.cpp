#include <bits/stdc++.h>
using namespace std;

/* 
    COUNT NO OF SQUARE SUBMETRIC
    
    brute force
        go to every element , count squares right, bottom

    tabulation is more intuitive


    check element , right bottom
    an element can how much square it be right bottom element

    matrix given
    1 1 1 1
    1 1 1 1
    1 1 1 1

    dp
    1 1 1 1
    1 2 2 2
    1 2 3 3

    minimal of (dp[i][j-1] , dp[i-1][j], dp[i][j-1])

*/

vector<vector<int>> matrix =  {{0,1,1,1}, {1,1,1,1}, {0,1,1,1}};
int n = matrix.size(), m = matrix[0].size();

int countSquares() {
    vector<vector<int>> dp(n, vector<int>(m, 0));  // Correct dimensions
    
    int totalSquares = 0;

    for (int i = 0; i < n; i++) dp[i][0] = matrix[i][0];
    for (int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // count
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            totalSquares += dp[i][j];
        }
    }

    return totalSquares;
}

int main() {
    cout << countSquares() << endl; // 15
    return 0;
}