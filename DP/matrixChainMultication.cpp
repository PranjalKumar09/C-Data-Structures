#include <bits/stdc++.h>
using namespace std;

/*
    PARTITION DP,



    * solve one portition at first then other
    -------------------------
    petitions
    -|------------------------
    --|-----------------------
    ---|----------------------
        '
        '
        '
    ------------------------|-


    MATRIX CHAIN MULTIPLICATION
    
    CAN BE MATRIX MULTIPLIED

    (10*20) x (20*30)


    which is better way to mutliply -> (AB)C or (AB)C
    
    * although both equal

    let A = 10*30, B = 30*5, C = 5*60
    (AB)C = 10*30*5 + 10*5*60 = 4500

    A(BC) = 10*30*60 + 30*5*60 = 27000


`




    given arr[] -> {10, 20, 30, 40, 50}
    N = 5

    A -> 10*20
    B -> 20*30
    C -> 30*40
    D -> 40*50

    ith Matrix Dimension-> A[i-1] * A[i]


    To solve partition DP
    1. Start with entire block, maps with i, j
        (ABCD)
         i--j
        (AB)(CD)  |  (A)(BCD)  |  (ABC)(D)
         ij  ij   |   ij i-j   |   i-j  ij
    So this is itself block

    2. Try all partitions, run loop to try all partitions
    3. Return best possible 2 problem


    {  - ,- , i, -, - ,- , j , -, -}
    f(i, j)b->  return min opertations to multiply i to j



    TC -> o (N * N) * N  = o(N3)
 */


vector<int> arr = {10, 20, 30, 40, 50};
int n = arr.size();


int f(int i, int j) {
    if (i >= j) return 0;

    int min_val = INT_MAX;
    for (int k = i; k < j; k++) 
        min_val = min(min_val, f(i, k) + f(k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
    
    return min_val;
}	
int f2(int i, int j, vector<vector<int>> &dp){
    if (i >= j) return 0;
    if (dp[i][j]!= -1) return dp[i][j];

    int min_val = INT_MAX;
    for (int k = i; k < j; k++) 
        min_val = min(min_val, f2(i, k, dp) + f2(k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j]);
    
    return dp[i][j] = min_val;
}

int f3(){
    vector<vector<int>> dp(n , vector<int>(n, 0 ));

// i always left from j -> n-1  to 1
// j right of i -> i+1 -> n-1

// i-1 (row fof first matrix so upto  0)

    for (int i = n-1 ; i > 0 ; i--){
        for (int j = i + 1; j < n; j++){
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
                dp[i][j] = min(
                    dp[i][j],
                    dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
        }
    }
    return dp[1][n-1];
}


int main(){
    cout << f(1, n) << endl;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << f2(1, n, dp) <<
     endl;



    return 0;
}
