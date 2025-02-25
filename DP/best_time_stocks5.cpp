
#include <bits/stdc++.h>
using namespace std;

vector<long> arr = {4, 9, 0, 4, 10};
int n = arr.size();
int limit_i = 2;



/*
    Buying stocks, once maximum profit with cooldown

        cant buy right after sell

    so if we sell, then  do i+2 from i+1


    and in f3 too n+1 to n+2
    and we reject f4 becuase in fully optimized solution it is 

*/


long f(int ind, bool buy , int limit){
    if (ind >= n || !limit) return 0;


    long profit = 0;
    if (buy)
        profit = max(-arr[ind]+f(ind+1, 0,limit), 0+f(ind+1, 1 , limit));
    else
        profit = max(arr[ind]+f(ind+2,1, limit-1), 0+f(ind+1, 0, limit));
    return profit;
}
long f2(int ind, bool buy, vector<vector<vector<long>>> &dp , int limit ){
    if (ind >= n || !limit) return 0;
    if (dp[ind][buy][limit-1]!= -1) return dp[ind][buy][limit-1]; 
    long profit = 0;
    if (buy)
        profit = max(-arr[ind]+f2(ind+1, 0, dp, limit), 0+f2(ind+1, 1, dp, limit));
    else
        profit = max(arr[ind]+f2(ind+2,1, dp, limit-1), 0+f2(ind+1, 0, dp, limit));
    return dp[ind][buy][limit-1] =   profit;
}


long f3(){
    vector<vector<vector<long>>>  dp(n+2,vector<vector<long>> (2, vector<long>(limit_i+1, 0)));

    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < 2; j++){
            for (int k = 1; k <= limit_i; k++){
                long profit = 0;
                if (j)
                    profit = max(-arr[i]+dp[i+1][0][k], 0+dp[i+1][1][k]);
                else
                    profit = max(arr[i]+dp[i+2][1][k-1], 0+dp[i+1][0][k]);
                dp[i][j][k] = profit;
            }
        }
    }

    return dp[0][1][limit_i];
}


long f4(){
    vector<vector<long>> front2(2, vector<long>(limit_i + 1, 0)), 
                         front1(2, vector<long>(limit_i + 1, 0)), 
                         cur(2, vector<long>(limit_i + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy < 2; buy++) {
            for (int k = 1; k <= limit_i; k++) {
                long profit = 0;
                if (buy)
                    profit = max(-arr[i] + front1[0][k], front1[1][k]);  
                else
                    profit = max(arr[i] + front2[1][k-1], front1[0][k]);  
                cur[buy][k] = profit;
            }
        }
        front2 = front1;  // Move front1 → front2
        front1 = cur;     // Move cur → front1
    }

    return front1[1][limit_i]; // Return the maximum profit with full transactions
}

int main(){
    cout << f(0, 1, limit_i) << endl;

    vector<vector<vector<long>>>  dp(n,vector<vector<long>> (2, vector<long>(limit_i, -1)));
    cout << f2(0, 1, dp, limit_i) << endl;

    cout << f3() << endl;
    cout << f4() << endl;




    return 0;  // Return 0 to indicate successful program execution
}