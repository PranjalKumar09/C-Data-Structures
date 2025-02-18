#include<bits/stdc++.h>
using namespace std;

/* UNBOUNDED KNAPSACK */

vector<int> wt = {2, 4, 6}, val = {5, 11, 13};
int W = 10, n = wt.size(); //



int fn(int i, int j) {
    if (j == 0) return 0;
    if (i < 0 || j < 0) return INT_MIN;

    int p  = fn(i, j - wt[i]) + val[i];
    int np = fn(i - 1, j);
    return max(p, np);
}

int fn2(int i, int j, vector<vector<int>> &dp) {
    if (j == 0) return 0;
    if (i < 0 || j < 0) return INT_MIN;
    if (dp[i][j]!=INT_MIN) return dp[i][j];

    int p  = fn2(i, j - wt[i], dp) + val[i];
    int np = fn2(i - 1, j, dp);
    return dp[i][j] =  max(p, np);
}

int fn3() {
    vector<vector<int>> dp(n, vector<int>(W + 1, INT_MIN)); 
    
    for (int i  = 0; i< n ; i++) dp[i][0] = 0;


    for (int i = 0; i < n ; i++){
        for (int j = 0; j <= W; j++){
        
        if ( j - wt[i] >= 0)
        dp[i][j]  = dp[i][ j - wt[i]] + val[i];
        
        if (i-1>= 0)
        dp[i][j] = max (dp[i - 1][j],dp[i][j]);
        }
    }

    return dp[n-1][W];
}




int fn4() {
    vector<int> prev(W + 1, -1), curr(W + 1, -1);
    
    prev[0] = curr[0] =  0;


    for (int i = 0; i < n ; i++){
        for (int j = 0; j <= W; j++){
        
        if ( j - wt[i] >= 0)
        curr[j]  = curr[ j - wt[i]] + val[i];
        
        if (i-1>= 0)
        curr[j] = max (prev[j],curr[j]);
        }
        prev = curr; 
    }

    return prev[W];
}


int main() {
    
    cout << fn(n - 1, W) << endl;

    vector<vector<int>> dp(n, vector<int>(W + 1, INT_MIN)); 
    cout << fn2(n - 1, W, dp) << endl;
    cout << fn3() << endl;
    cout << fn4() << endl;




    return 0; // Return 0 to indicate successful program execution
}

