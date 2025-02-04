
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int k, n;

/*
    COIN CHANGE 2


    * we need different default values in different dp
*/

int fn(int i, int j){
    if (j == 0) return 1;
    if (i < 0  || j < 0) return 0;
    return fn(i, j-arr[i]) + fn(i -1, j);
}

int fn2(int i, int j, vector<vector<int>>& dp){
    if (j == 0) return 1;
    if (i < 0  || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j]  = fn2(i, j-arr[i], dp) + fn2(i -1, j, dp);
}

int fn3(){
    vector<vector<int>> dp(n, vector<int>(k+1, 0));

    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int j = 0; j <= k; j++)
        if (j % arr[0] == 0) dp[0][j] = 1;
    
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= k; j++){
            dp[i][j] = dp[i-1][j];
            if (j - arr[i] >= 0) dp[i][j] += dp[i][j-arr[i]];
        }

    return dp[n-1][k];
}

int fn4(){
    vector<int>  prev(k+1,0);

    prev[0] = 1;
    for (int j = 0; j <= k; j++)
        if (j % arr[0] == 0) prev[j] = 1;


    for (int i = 1; i < n; i++){
        vector<int> curr(k+1, 0);
        curr[0] = 1;  // Base case
        for (int j = 1; j <= k; j++){

            curr[j] += prev[j];
            if (j - arr[i] >= 0) curr[j] += curr[j-arr[i]];
        }
        prev  = curr;
}
    return prev[k];
}
int fn5(){
    vector<int> prev(k + 1, 0), current(k + 1, 0); // For the current row

    prev[0] = 1;
    for (int j = 0; j <= k; j++)
        if (j % arr[0] == 0) prev[j] = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            current[j] = prev[j]; 

            if (j - arr[i] >= 0) {
                current[j] += current[j - arr[i]]; 
            }
        }

        // Move current[] to prev[] for the next iteration
        prev = current;
    }

    // The answer will be in prev[k] after the last iteration
    return prev[k];
}
void solve(){

    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    cout << fn2(n-1, k, dp) << endl;
    cout << fn3() << endl;
    cout << fn(n-1, k) << endl;
    cout << fn4() << endl;
    cout << fn5() << endl;
}



int main() {
    arr = {1, 2, 3};
    k = 4, n = arr.size();

    solve();
    return 0; // Return 0 to indicate successful program execution
}
