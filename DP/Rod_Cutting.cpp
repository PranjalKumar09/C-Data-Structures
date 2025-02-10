#include<bits/stdc++.h>
using namespace std;

/* ROD CUTTING 
this is similar to unbounded knapsack,
here we have int n, as length of rod & price array of size n



*/

vector<int> arr = {2, 5, 7, 8 , 10}; 
int n = arr.size();



int fn(int i, int j) {
    if (j == 0) return 0;
    if (i < 0 || j < 0) return INT_MIN;
    // cout << "i->" << i << " j->" << j << endl;
    int rodLen = i + 1;
    int p  = fn(i, j - rodLen) + arr[i];
    int np = fn(i - 1, j);
    return max(p, np);
}


int fn2(int i, int j,vector<vector<int>> &dp) {
    if (j == 0) return 0;
    if (i < 0 || j < 0) return INT_MIN;
    if (dp[i][j] != INT_MIN) return dp[i][j];
    cout << "i->" << i << " j->" << j << endl;
    int rodLen = i + 1;
    int p  = fn2(i, j - rodLen, dp) + arr[i];
    int np = fn2(i - 1, j, dp);
    return dp[i][j] = max(p, np);
}

int fn3() {
    vector<vector<int>> dp(n ,  vector<int>(n+1, INT_MIN));
    for (int i = 0; i<n; i++) dp[i][0] = 0;
    
    for (int i = 0; i < n ; i++)
        for (int j = 0; j<n+1; j++){
            int rodLen = i+1;
            if (j - rodLen >= 0) 
            dp[i][j]= dp[i][j-rodLen] + arr[i];
            if (i - 1 >= 0)
            dp[i][j]= max(dp[i][j],  dp[i-1][j] );
        }
    return dp[n-1][n];
}
int fn4(){
    vector<int> curr(n+1, INT_MIN), prev(n+1, INT_MIN);
    prev[0] = curr[0] = 0;

    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n+1; j++){
            int rodLen = i+1;
            if (j - rodLen >= 0) 
            curr[j]= prev[j-rodLen] + arr[i];
            curr[j]= max(curr[j],  prev[j] );
        }
        prev = curr;
    }

    return prev[n];

}


int fn5(){
    vector<int> curr(n+1, INT_MIN);
    curr[0] = 0;

    for (int i = 0; i < n ; i++)
        for (int j = 0; j < n+1; j++){
            int rodLen = i+1;

            if (j - rodLen >= 0) 
            curr[j]= max(curr[j],  curr[j-rodLen] + arr[i]);
        }


    return curr[n];

}


int main() {
    
    cout << fn(n - 1, n) << endl;
    vector<vector<int>> dp(n ,  vector<int>(n+1, INT_MIN));
 
    cout << fn2(n-1, n, dp) << endl;

    cout << fn3() << endl;
    cout << fn4() << endl;
    cout << fn5() << endl;



    return 0; // Return 0 to indicate successful program execution
}

