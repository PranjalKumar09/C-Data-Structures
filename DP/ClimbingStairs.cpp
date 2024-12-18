#include <bits/stdc++.h>
using namespace std;

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


 */

int rec(int n){
    if (n==0 || n==1) return 1;
    return rec(n-1) + rec(n-2);
}

int dp(int n){
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int optimized(int n){
    if (n==0 || n==1) return 1;
    int a=1, b=1;
    for(int i=2;i<=n;i++){
        int temp=a+b;
        a=b;
        b=temp;
    }
    return b;
}

int main() {
    int n = 100;
    cout << "Optimized approach result: " << optimized(n) << endl;
    cout << "Recursive approach result: " << rec(n) << endl;
    cout << "Dynamic Programming approach result: " << dp(n) << endl;

    return 0;

}

