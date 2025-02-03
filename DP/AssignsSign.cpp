
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int k, n;

/*
    ASSIGN SIGN

        divide into two subset such that
            subset 1 - subset 2 = k

    similar to DP/CountPartitionGivenDifference.cpp problem



*/


int fn5() {
    vector<int> dp(k+1, 0);
    dp[0] = 1;  // Base case

    for (int i = 0; i < n; i++) 
        for (int j = k; j >= arr[i]; j--)   
            dp[j] = dp[j] + dp[j - arr[i]];
        
    

    return dp[k];
}

void countPartitions(){

    int total = accumulate(arr.begin(), arr.end(), 0);

    if (total < k || (total - k) % 2 ){
        cout << 0 << endl;
        return;
    }
    cout << fn5() << endl;
    k = (total - k) / 2;
}





void assignSign(){
    countPartitions();
}


int main() {
    arr = {1, 2, 3, 1};
    k = 3;

    n = arr.size();
    countPartitions() ;

    return 0;  // Return 0 to indicate successful program execution
}
