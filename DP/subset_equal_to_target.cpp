#include <bits/stdc++.h>
using namespace std;


vector<int> arr;
int k, n;


/*
    DP on subsequence / Subset
    =================

    Any contigious/non contigious part of array




    Subset equal to K -> return bool
    ================================
    express (i, target)
    not take | take



    In dp it not only tell about K, it also tells whether it is reachable to K or not

        0  1  2  ...  K
    0                   
    1                   
    '
    '                    
    n-1 -  -  -  ...  * -> tells whether it is reachable to K or not using subset of array
    similarly  -  -  - tells whether it is possible to reach  0 to k

    similarly every point in dp, signify anything,, like index means upto that point possible to get current target

*/

bool fn(int i, int target){
    if (target == 0) return true;
    if (i == -1 || target  < 0) return false;


    return fn(i-1, target-arr[i]) || fn(i-1, target);
}



bool fn2(int i, int target,  vector<vector<int> > &dp){
    if (target == 0) return true;
    if (i == -1|| target  < 0) return false;
    if (dp[i][target] != -1) return dp[i][target]; 
    // cout << " i->" << i << " target->" << target << endl;

    return  dp[i][target] = fn2(i-1, target-arr[i], dp) || fn2(i-1, target, dp);
}

bool fn3(){
    // we converting vector<vector<int> >  to vector<vector<bool> >

    vector<vector<bool> > dp(n ,vector<bool>(k+1, false));
    for (int i = 0; i < n; i++) dp[i][0] = true;

 // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (arr[0] <= k) {
            dp[0][arr[0]] = true;
    }


    for (int i = 1; i < n ; i++){
        for (int j = 1; j < k+1; j++ )
            dp[i][j] = dp[i-1][j] || (j-arr[i] >= 0 ? dp[i-1][j-arr[i]] : false);
    }

    return dp[n-1][k];
}

bool fn4(){
    vector<bool> dp(k+1, false), prev(k+1, false);
    dp[0] = true; // A sum of 0 is always possible

    for (int i = 0; i < n; i++){ // Start from i = 0 to include arr[0]
        prev[0] = true; // Reset prev[0] in every iteration

        for (int j = 1; j <= k; j++)
            prev[j] = dp[j] || (j >= arr[i] ? dp[j - arr[i]] : false);

        dp = prev; // Copy prev to dp for next iteration
    }

    return dp[k];
}


bool fn5() {
    vector<bool> dp(k+1, false);
    dp[0] = true;  // Base case

    for (int i = 0; i < n; i++) 
        for (int j = k; j >= arr[i]; j--)   
            dp[j] = dp[j] || dp[j - arr[i]];
        
    

    return dp[k];
}





bool subsetSumToK(){

cout << "Sol 1 (Recursive): " << fn(n-1, k) << endl;

vector<vector<int>> dp(n, vector<int>(k+1, -1));
cout << "Sol 2 (Memoization): " << fn2(n-1, k, dp) << endl;

cout << "Sol 3 (Tabulation 2D DP): " << fn3() << endl;
cout << "Sol 4 (Optimized 2-row DP): " << fn4() << endl;
cout << "Sol 5 (Optimized 1D DP): " << fn5() << endl;
return true;
}

int main() {
arr = {1, 2, 5, 9};
k = 8;
    n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK())
        cout << "Found";
    else
        cout << "Not found";
    cout << endl;
    return 0;
}
