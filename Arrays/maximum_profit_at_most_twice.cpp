/* 
DP 
TC-> O(N) 
SC-> O(N) 

at dp[i] we will store max profit of 2 transactions from right 
ma -> first tranasaction store last value (sell price)     (right to left)      it is updated as maximum     
mi -> second tranasaction store last value (cost price)    (left to right)      it is updated as manimum 

dp[i] =  => max(dp[i+1] , ma-a[i])              (right to left)
dp[i] =  => max(dp[i-1] , dp[i] + (a[i]- mi))      (left to right)


Simple approach 
TC-> O(N) 
SC-> O(1) 


 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


int dp_method (vector<int> &arr){
    int n = arr.size();
    int ma = arr[n-1] , mi = arr[0] ;
    vector<int> dp(n,0);
    for (int i = n-2; i >= 0; i--){
        ma = max(ma, arr[i]);
        dp[i] = max(dp[i+1] , ma-arr[i]);
        }
    for (int i = 1; i<n; i++){
        mi = min(mi, arr[i]);
        dp[i]  = max(dp[i-1] ,  dp[i]+arr[i]- mi );
    }
    return dp[n-1];
}

int simpler(vector<int>& arr){
    int n = arr.size();
    int buy1, buy2, profit1, profit2;
    profit1 = profit2 = 0;
    buy1 = buy2 = INT_MAX;
    for (int i = 0 ; i<n ; i++) {
        buy1 = min(buy1, arr[i]);
        profit1 = max(profit1, arr[i] - buy1);
        buy2 = min(buy2, arr[i] - profit1);  // effective cost price
        profit2 = max(profit2, arr[i] - buy2);

    }
    return profit2;
}




int main(){
    vector<int> arr = {100, 30, 15, 10, 8, 25, 80};
    cout<<dp_method(arr)<<endl;
    cout<<simpler(arr)<<endl;
    


}