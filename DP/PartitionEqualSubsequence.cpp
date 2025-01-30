#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int n ;

/*
Partition  Equal Subset

    Exactly 2 subset

    subset should have equal sum

    now we can do like array first find sum of all element 
        if sum is odd return false
        else we will check by recursion that subset sum equal to k
            (already done same problem) in DP/subset_equal_to_target.cpp
        
*/

bool fn5(int k) {
    vector<bool> dp(k+1, false);
    dp[0] = true;  // Base case

    for (int i = 0; i < n; i++) 
        for (int j = k; j >= arr[i]; j--)   
            dp[j] = dp[j] || dp[j - arr[i]];
        
    

    return dp[k];
}



bool canPartition(){
    int sum = 0;
    for (int i: arr)
        sum += i;
    if (sum % 2) return false;
    return fn5(sum/2);
}

int main(){
    arr = {2, 3, 3, 3, 4, 5};
    n= arr.size();
    cout << canPartition() << endl;

    return 0;

}

