#include <bits/stdc++.h>
using namespace std;


vector<int> arr;
int k, n;


/*
    Count Subsequence Sum Equals K
    --------------------------------
    
    similar to other subsequence problem
        we can do by returning -> pick + nonPick

    just change true to 1 , false to 0, || to +


    only larger than 0 (solved here)

        now if there were 0 it will seprate to solve it ->
            only larger than 0 (solved here) * pow (2 ,#0)
            also remove zero condtion done here

            changing conditions like ->
            
            if (target == 0){
                if (i > -1 && arr[i] == 0) return 2;
                return 1;
            }
*/

int fn(int i, int target){
    if (target == 0) return 1;
    if (i == -1 || target  < 0) return 0;


    return fn(i-1, target-arr[i]) + fn(i-1, target);
}



int fn2(int i, int target,  vector<vector<int> > &dp){
    if (target == 0) return 1;
    if (i == -1|| target  < 0) return 0;
    if (dp[i][target] != -1) return dp[i][target]; 
    // cout << " i->" << i << " target->" << target << endl;

    return  dp[i][target] = fn2(i-1, target-arr[i], dp) + fn2(i-1, target, dp);
}

int fn3(){

    vector<vector<int> > dp(n ,vector<int>(k+1, false));
    for (int i = 0; i < n; i++) dp[i][0] = true;

 // Base case    Count Subsequence Sum Equals K
    if (arr[0] <= k)      dp[0][arr[0]] = 1;
    


    for (int i = 1; i < n ; i++){
        for (int j = 1; j < k+1; j++ )
            dp[i][j] = dp[i-1][j] + (j-arr[i] >= 0 ? dp[i-1][j-arr[i]] : 0);
    }

    return dp[n-1][k];
}

int fn4(){
    vector<int> dp(k+1, false), prev(k+1, false);
    dp[0] = true; // A sum of 0 is always possible

    for (int i = 0; i < n; i++){ // Start from i = 0 to include arr[0]
        prev[0] = true; // Reset prev[0] in every iteration

        for (int j = 1; j <= k; j++)
            prev[j] = dp[j] + (j >= arr[i] ? dp[j - arr[i]] : false);

        dp = prev; // Copy prev to dp for next iteration
    }

    return dp[k];
}



int fn5() {
    vector<int> dp(k+1, 0);
    dp[0] = 1;  // Base case

    for (int i = 0; i < n; i++) 
        for (int j = k; j >= arr[i]; j--)   
            dp[j] = dp[j] + dp[j - arr[i]];
        
    

    return dp[k];
}





void subsetSumToK(){

cout << "Sol 1 (Recursive): " << fn(n-1, k) << endl;

vector<vector<int>> dp(n, vector<int>(k+1, -1));
cout << "Sol 2 (Memoization): " << fn2(n-1, k, dp) << endl;

cout << "Sol 4 (Optimized 2-row DP): " << fn4() << endl;
cout << "Sol 5 (Optimized 1D DP): " << fn5() << endl;
cout << "Sol 3 (Tabulation 2D DP): " << fn3() << endl;
}

int main() {
    arr = {1, 2, 2, 3};
    k = 3;
    n = arr.size();

   subsetSumToK();

    return 0;
}