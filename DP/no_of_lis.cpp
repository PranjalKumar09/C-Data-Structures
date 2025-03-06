#include <bits/stdc++.h>
using namespace std;

/*
    NO OF LONGEST INCREASING SUBSEQUENCE (No of LIS)

    arr[]   = {1, 3, 5, 4, 7}
    dp[]    = {1, 2, 3, 3, 4}
    count[] = {1, 1, 1 ,1, 2}
 */

vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 2};
int n = arr.size();
int fn5(){
    int maxi = 0;


    vector<int> dp(n, 1), count (n ,1);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int prev = 0; prev < i; prev++) {
            if (arr[i] > arr[prev] && dp[i] < dp[prev] + 1){
                dp[i] = dp[prev] + 1;
                count[i] = count[prev];
                }
            else if (arr[i] > arr[prev] && dp[i] == dp[prev] + 1){
                count[i] += count[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (dp[i] == maxi) cnt += count[i];
    }
    return cnt;
}



int main(){
    cout << fn5() << endl;
    return 0;

}