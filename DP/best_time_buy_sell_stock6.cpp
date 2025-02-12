
#include <bits/stdc++.h>
using namespace std;

vector<long> arr = {1, 3, 2, 8, 4, 9};
int n = arr.size();
int fees = 2;



/*
    BUYING STOCKS, ONCE MAXIMUM PROFIT WITH TRANSACTION FEES

*/


long f(int ind, bool buy ){
    if (ind == n) return 0;

    long profit = 0;
    if (buy)
        profit = max(-arr[ind]+f(ind+1, 0)-fees, 0+f(ind+1, 1));
    else
        profit = max(arr[ind]+f(ind+1,1), 0+f(ind+1, 0));
    return profit;
}
long f2(int ind, bool buy ,vector<vector<long>> &dp ){
    if (ind == n) return 0;
    if (dp[ind][buy]!= -1) return dp[ind][buy]; 
    long profit = 0;
    if (buy)
        profit = max(-arr[ind]+f2(ind+1, 0, dp)-fees, 0+f2(ind+1, 1, dp));
    else
        profit = max(arr[ind]+f2(ind+1,1, dp), 0+f2(ind+1, 0, dp));
    return dp[ind][buy] =   profit;
}


long f3(){
    vector<vector<long>> dp(n+1, vector<long>(2, 0));

    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < 2; j++){
          
            long profit = 0;
            if (j)
                profit = max(-arr[i]+dp[i+1][0]-fees, 0+dp[i+1][1]);
            else
                profit = max(arr[i]+dp[i+1][1], 0+dp[i+1][0]);
            dp[i][j] = profit;
        }
    }

    return dp[0][1];
}


long f4(){
    vector<long> ahead(2, 0), curr(2, 0);

    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < 2; j++){
            long profit = 0;
            if (j)
                profit = max(-arr[i] + ahead[0]-fees, ahead[1]);
            else
                profit = max(arr[i] + ahead[1], ahead[0]);
            curr[j] = profit;
        }
        ahead = curr;  // Move current state to ahead for next iteration
    }

    return ahead[1];
}


int main(){
    cout << f(0, 1) << endl;

    vector<vector<long>> dp(n, vector<long>(2, -1));
    cout << f2(0, 1, dp) << endl;

    cout << f3() << endl;
    cout << f4() << endl;




    return 0;  // Return 0 to indicate successful program execution
}