#include <bits/stdc++.h>
using namespace std;

/*
    LONGEST BITONIC SUBSEQUENCE

    its graph which first increase then decrease

    strictly increasing or strictly decreasing can be bitonic


    
    arr[]= { 1, 11, 2, 10, 4, 5, 2, 1 };
    dp[] = { 1,  2, 2,  3, 3, 4, 2, 1 }
    dp[2]= { 1,  5, 2,  4, 3, 3, 2, 1 }



*/



int longestBitonicSubsequence(vector<int>& arr,  int n) {

    vector<int> dp1(n, 1), dp2(n, 1);
    for (int i = 0; i < n; i++) {
        dp1[i] = 1;
        for (int prev = 0; prev < i; prev++) {
            if (arr[i] > arr[prev] && dp1[i] < dp1[prev] + 1)
                dp1[i] = dp1[prev] + 1;
        }
    }

     for (int i = n-1; i > -1; i--) {
        dp2[i] = 1;
        for (int prev = n-1; prev > i; prev--) {
            if (arr[i] > arr[prev] && dp2[i] < dp2[prev] + 1)
                dp2[i] = dp2[prev] + 1;
        }
    }

    int maxi = 0;

    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }


    return maxi;


}



int main() {
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = arr.size();
    cout << longestBitonicSubsequence(arr, n) << endl;
    return 0;
}