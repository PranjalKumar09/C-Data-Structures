
#include <bits/stdc++.h>
using namespace std;

/* 
    Partition Array for Maximum Sum

    An array arr[] of size n.
    A number k representing the maximum partition size.


    Partition the array into contiguous subarrays (with size ≤ k) to maximize the sum of the array after replacing each subarray with its maximum element.


        arr = [1,15,7,9,2,5,10], k = 3
Output
: 84
Explanation:
    The partition will be the following to get the largest sum:
    [1, 15, 7 | 9 | 2, 5, 10]. 
After replacing the elements of each subarray with its maximum, the array will look like this:[15,15,15,9,10,10,10] and the sum will be 84


 */
vector<int>  arr = {1,15,7,9,2,5,10};
int k = 3, n = arr.size();


int f(int i){
    if (i == n) return 0;
    
    int len = 0;
    int maxi = INT_MIN, maxi_ans = INT_MIN;

    for (int j = i; j < min(i+k, n); j++){
        len++;
        maxi = max(maxi, arr[j]);
        maxi_ans = max(maxi_ans, maxi * len + f(j+1));
    }
    return maxi_ans;
}



int f1(int i, vector<int> &dp){
    if (i == n) return 0;
    if (dp[i]!= -1) return dp[i];

    int len = 0;
    int maxi = INT_MIN, maxi_ans = INT_MIN;

    for (int j = i; j < min(i+k, n); j++){
        len++;
        maxi = max(maxi, arr[j]);
        maxi_ans = max(maxi_ans, maxi * len + f1(j+1, dp));
    }
    return dp[i] = maxi_ans;
}

int f2(){
    vector<int> dp(n+1, 0);

    for (int i = n-1; i >= 0; i--){

        int len = 0;
        int maxi = INT_MIN, maxi_ans = INT_MIN;

        for (int j = i; j < min(i+k, n); j++){
            len++;
            maxi = max(maxi, arr[j]);
            maxi_ans = max(maxi_ans, maxi * len + dp[j+1]);
        }
        dp[i] = maxi_ans;
    }

    return dp[0];
}


int main(){

    cout << endl << f(0) << endl;
    vector<int> dp(n, -1);
    cout << f1(0, dp) << endl;
    cout << f2() << endl;
    
    return 0;

}