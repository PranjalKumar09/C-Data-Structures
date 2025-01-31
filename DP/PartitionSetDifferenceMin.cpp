#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int n ;

/*
Partition set such that difference b/w absolute difference minimum

    read notes of DP/subset_equal_to_target.cpp

    so last row , sginify lot, we can calculate S1 - S2,
    S2 => S - S1 we have to minimize -> |S1- S2|

    now is S1 is correct S2 will correct too means both value in dp will correct
    so we will check upto only sum/2 (more optimized)v
*/

vector<bool> fn5(int k) {
    vector<bool> dp(k+1, false);
    dp[0] = true;  // Base case

    for (int i = 0; i < n; i++) 
        for (int j = k; j >= arr[i]; j--)   
            dp[j] = dp[j] || dp[j - arr[i]];
        
    

    return dp;
}



int solve(){
    int sum = 0;
    for (int i: arr)
        sum += i;
    vector<bool> dp = fn5(sum/2);

    int ans  = INT_MAX;
    for (int i = sum/2; i > -1; i--) // i - (sum - i) = 2i - sum , abs form
        if (dp[i]) {ans = sum  - 2*i;
        break;} // first answer came will lowest
    return ans;

}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << solve();

    return 0;
}
