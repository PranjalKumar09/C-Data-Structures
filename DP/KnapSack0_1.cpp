#include <bits/stdc++.h>
using namespace std;


vector<int> arr, weights;
int k, n;


/*


*/

int fn(int i, int target){
    if (target == 0) return 0;
    if (i == -1 || target  < 0) return INT_MIN;

    return max(fn(i-1, target-weights[i]) + arr[i] , fn(i-1, target));
}



int fn2(int i, int target,  vector<vector<int> > &dp){
    if (target == 0) return 0;
    if (i == -1|| target  < 0) return INT_MIN;
    if (dp[i][target] !=-1) return dp[i][target]; 
    // cout << " i->" << i << " target->" << target << endl;

    return  dp[i][target] = max( fn2(i-1, target-weights[i], dp) + arr[i], fn2(i-1, target, dp));
}


int fn3(){
    vector<vector<int> > dp(n, vector<int>(k+1, -1));
    
    for (int i = 0; i < n; i++) dp[i][0] = 0;

    if (weights[0] <= k) dp[0][weights[0]] = arr[0];

    for (int i = 1; i < n; i++) 
        for (int j = 1; j < k+1; j++)
            dp[i][j] = max(dp[i-1][j], j-weights[i] >= 0 ? dp[i-1][j-weights[i]] + arr[i] : INT_MIN);


    return dp[n-1][k];
}

int fn4(){
   vector<int> dp(k+1 -1), prev(k+1, -1);
    
    dp[0] = prev[0] =  0;

    if (weights[0] <= k) dp[weights[0]] = arr[0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < k+1; j++)
            prev[j] = max(dp[j], j-weights[i] >= 0 ? dp[j-weights[i]] + arr[i] : INT_MIN);
        dp = prev;}


    return dp[k];
}

int fn5(){
    vector<int> dp(k+1 -1);
    
    dp[0] =  0;

    if (weights[0] <= k) dp[weights[0]] = arr[0];

    for (int i = 1; i < n; i++) 
        for (int j = 1; j < k+1; j++)
            dp[j] = max(dp[j], j-weights[i] >= 0 ? dp[j-weights[i]] + arr[i] : INT_MIN);


    return dp[k];
}
int fn6(){
    vector<int> dp(k+1,0);
    
    dp[0] =  0;

    // if (weights[0] <= k) dp[weights[0]] = arr[0];

    for (int i = 1; i < n; i++)
        for (int j = k; j >= weights[i]; j--)
            dp[j] = max(dp[j], dp[j - weights[i]] + arr[i]);



    return dp[k];
}



int main() {
    weights = {1, 2, 3};
    arr = {10, 20, 30};
    k = 5;  // Max weight capacity of the knapsack
    n = weights.size();
    
    cout << fn(n-1  , k) << endl;

    vector<vector<int> > dp(n, vector<int>(k+1, -1));
    cout << fn2(n-1, k, dp) << endl;

    cout << fn3() << endl;
    cout << fn4() << endl;
    cout << fn5() << endl;
    cout << fn6() << endl;

    // 50
    return 0;
}
