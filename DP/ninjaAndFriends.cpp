#include  <bits/stdc++.h>
#include<string>
using namespace std;
/*
3-d DP : Ninja and his friends
so each can diagnoaly, veritcally, they both
total possiblity = 3*3 = 9


but for vertical mean for height we can do common-> h
-> h, x1, x2
*/
int n, m;
vector<vector<int>> matrix;

int f1(int h, int y1, int y2 ){
    if (h==n) return 0;
    if (y1 < 0 || y2 < 0 || y1 >= m || y2 >= m) return INT_MIN;

    int ans =   INT_MIN;
    for (int x = -1; x < 2; x++)
        for (int y = -1; y < 2 ; y++){
            if (y1  == y2 )
                ans = max(ans,  matrix[h][y1] + f1(h+1, y1+x, y2+y));
            else
                ans = max(ans, matrix[h][y1] + matrix[h][y2] + f1(h+1, y1 + x, y2 + y));
        }
    return ans;
}


int f2(int h, int y1, int y2 ,  vector<vector<vector<int>>> &dp){
    if (h==n) return 0;
    if (y1 < 0 || y2 < 0 || y1 >= m || y2 >= m) return INT_MIN;

            if (dp[h][y1][y2]!=INT_MIN) return dp[h][y1][y2];  // if already computed then return it.

    int ans =   INT_MIN;
    for (int x = -1; x < 2; x++)
        for (int y = -1; y < 2 ; y++){
            if (y1  == y2 )
                ans = max(ans,  matrix[h][y1] + f2(h+1, y1+x, y2+y, dp));
            else
                ans = max(ans, matrix[h][y1] + matrix[h][y2] + f2(h+1, y1 + x, y2 + y, dp));
        }
    return dp[h][y1][y2] =   ans;
}

int f3(){


    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,INT_MIN)));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++){
            if (i==j)
            dp[n-1][i][j] = matrix[n-1][i];
            else
                dp[n-1][i][j] = matrix[n-1][i] + matrix[n-1][j];
        }



    for (int z = n-2; z > -1; z--)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++){
                int ans = INT_MIN;
                for (int x = -1; x < 2; x++)
                    for (int y = -1; y < 2 ; y++){
 int newY1 = i + x;
                    int newY2 = j + y;

                    // Check bounds before accessing dp array
                    if (newY1 < 0 || newY1 >= m || newY2 < 0 || newY2 >= m) continue;

                    if (i == j)
                        ans = max(ans, matrix[z][i] + dp[z + 1][newY1][newY2]);
                    else
                        ans = max(ans, matrix[z][i] + matrix[z][j] + dp[z + 1][newY1][newY2]);
                
                    }
                dp[z][i][j] = ans;
            }


    return dp[0][0][m-1];
}
int f4(){
    vector<vector<int>> dp(m, vector<int>(m , INT_MIN));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = (i == j) ? matrix[n-1][i] : matrix[n-1][i] + matrix[n-1][j];

    for (int z = n-2; z > -1; z--) {
        vector<vector<int>> new_dp(m, vector<int>(m, INT_MIN)); // Temporary DP table
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int ans = INT_MIN;
                
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int newY1 = i + x, newY2 = j + y;

                        if (newY1 < 0 || newY1 >= m || newY2 < 0 || newY2 >= m) continue;

                        int value = (i == j) ? matrix[z][i] : matrix[z][i] + matrix[z][j];
                        ans = max(ans, value + dp[newY1][newY2]);
                    }
                }
                new_dp[i][j] = ans;
            }
        }
        dp = new_dp; // Move to the next row
    }
    
    return dp[0][0];
}

int f5(){
    vector<int> dp(m, INT_MIN), prev(m, INT_MIN); 

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            prev[j] = (i == j) ? matrix[n-1][i] : matrix[n-1][i] + matrix[n-1][j];
        }
    }

    // Iterate from row z = n-2 to 0
    for (int z = n-2; z >= 0; z--) {
        dp.assign(m, INT_MIN);  // Reset DP for current row

        for (int i = 0; i < m; i++) {
            for (int j = m - 1; j >= 0; j--) {  // Reverse iteration prevents overwriting
                int ans = INT_MIN;

                // Try all possible moves for both paths
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int newY1 = i + x, newY2 = j + y;
                        if (newY1 < 0 || newY1 >= m || newY2 < 0 || newY2 >= m) continue;

                        int value = (i == j) ? matrix[z][i] : matrix[z][i] + matrix[z][j];
                        ans = max(ans, value + prev[newY2]);  // Use prev row values
                    }
                }
                dp[j] = ans;  // Store in current row
            }
        }
        swap(dp, prev);  // Move to the next row
    }

    return prev[0];  // Final result
}


int maximumChocolates(){
    // return f1(0, 0, m-1);


    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,INT_MIN)));
    // return f2(0, 0, m-1, dp); // for first row
    // return f3();
    return f5();
}



int main(){

    matrix = {  {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    n = matrix.size();
    m = matrix[0].size();

    // Call the maximumChocolates function and print the result
    cout << maximumChocolates();

    return 0;
}



