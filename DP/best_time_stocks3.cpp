
#include <bits/stdc++.h>
using namespace std;

vector<long> arr = {3, 3, 5, 0, 0, 3, 1, 4};
int n = arr.size();
int limit_i = 2;



/* 
    Buying stocks, once maximum profit 3
        same like just 2nd , but here we can do atmost 2 transaction
        even this solution to at most k limit
*/


long f(int ind, bool buy , int limit){
    if (ind == n || !limit) return 0;


    long profit = 0;
    if (buy)
        profit = max(-arr[ind]+f(ind+1, 0,limit), 0+f(ind+1, 1 , limit));
    else
        profit = max(arr[ind]+f(ind+1,1, limit-1), 0+f(ind+1, 0, limit));
    return profit;
}
long f2(int ind, bool buy, vector<vector<vector<long>>> &dp , int limit ){
    if (ind == n || !limit) return 0;
    if (dp[ind][buy][limit-1]!= -1) return dp[ind][buy][limit-1]; 
    long profit = 0;
    if (buy)
        profit = max(-arr[ind]+f2(ind+1, 0, dp, limit), 0+f2(ind+1, 1, dp, limit));
    else
        profit = max(arr[ind]+f2(ind+1,1, dp, limit-1), 0+f2(ind+1, 0, dp, limit));
    return dp[ind][buy][limit-1] =   profit;
}


long f3(){

    vector<vector<vector<long>>>  dp(n+1,vector<vector<long>> (2, vector<long>(limit_i+1, 0)));
    
    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < 2; j++){
            for (int k = 1; k <= limit_i; k++){
                long profit = 0;
                if (j)
                    profit = max(-arr[i]+dp[i+1][0][k], 0+dp[i+1][1][k]);
                else
                    profit = max(arr[i]+dp[i+1][1][k-1], 0+dp[i+1][0][k]);
                dp[i][j][k] = profit;
            }
        }
    }

    return dp[0][1][limit_i];
}


long f4(){
    vector<vector<long>>   ahead(2 , vector<long>(limit_i+1, 0)), curr(2 , vector<long>(limit_i+1, 0));

    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < 2; j++)
            for (int k  = 1;k <= limit_i; k++){
            long profit = 0;
            if (j)
                profit = max(-arr[i] + ahead[0][k], ahead[1][k]);
            else
                profit = max(arr[i] + ahead[1][k-1], ahead[0][k]);
            curr[j][k] = profit;}
        
        ahead = curr;  // Move current state to ahead for next iteration
    }

    return ahead[1][limit_i]; //
}


int main(){
    cout << f(0, 1, limit_i) << endl;

    vector<vector<vector<long>>>  dp(n,vector<vector<lo ng>> (2, vector<long>(limit_i, -1)));
    cout << f2(0, 1, dp, limit_i) << endl;

    cout << f3() << endl;
    cout << f4() << endl;




    return 0;  // Return 0 to indicate successful program execution
}