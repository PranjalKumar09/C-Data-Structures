

/* 
    Burst Ballon

    by bursting ballon we get addition of coins


  N = 4, array[] = {3, 1, 5, 8}
Output
: 167
Explanation:
First, we will burst the second balloon with 
the value 1. Coins = 3*1*5 = 15.
Second, we will burst the balloon with the 
value 5. Coins = 3*5*8 = 120.
Third, we will burst the balloon with the 
value 3. Coins = 1*3*8 = 24.
Fourth, we will burst the balloon with the 
value 8. Coins = 1*8*1 = 8.
So, the total number of coins we can collect 
is 167. This is the maximum number of coins we 
can collect.
09



add 1 at end to remove complexity => 1, 3, 1, 5, 8, 1

think from reverse like selecting k (at first) means k is last guy
so a[i-1] * a[k] * a[j+1]


 */


vector<int> arr = {3, 1, 5, 8};
int n = arr.size();




int f(int i, int j){
    if(i > j) return 0;
    int max_coins = INT_MIN;
    for(int k = i; k <= j; k++){
        int cost = arr[i-1]*arr[k]*arr[j+1] + f(i, k-1) +  f(k+1, j);
        max_coins = max(max_coins, cost);  

    }
    return max_coins;
}

int f1(int i, int j, vector<vector<int> > &dp){
    if(i > j) return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    int max_coins = INT_MIN;
    for(int k = i; k <= j; k++){
        int cost = arr[i-1]*arr[k]*arr[j+1] + f(i, k-1) +  f(k+1, j);
        max_coins = max(max_coins, cost);  

    }
    return dp[i][j]=max_coins;
}

int f3(){
    vector<vector<int> > dp( n+2 ,vector<int>(n+2, 0) ); // for safety n+2

    for (int i = n; i >= 1; i--){
        for (int j = i; j <= n; j++){
        int max_coins = INT_MIN;
             for(int k = i; k <= j; k++){
                int cost = arr[i-1]*arr[k]*arr[j+1] + dp[i][k-1] + dp[k+1][j]; //f(i, k-1) +  f(k+1, j);
                max_coins = max(max_coins, cost);  

    }
    dp[i][j] = max_coins; 
        }
    }


    return dp[1][n];
}

int main(){
    arr.insert(arr.begin(), 1);
    arr.push_back(1);

    cout << f(1, n) << endl;
    
    
    // vector<vector<int> > dp( n+1 ,vector<int>(n+1, -1) );
    vector<vector<int> > dp( n+2 ,vector<int>(n+2, -1) ); // for safety n+2
    cout << f1(1, n, dp) << endl;

    cout << f3() << endl;

    return 0; 

}