#include <bits/stdc++.h>
using namespace std;

/*

 */

int rec(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return rec(n - 1) + rec(n - 2);
}

int dp(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int optimized(int n)
{

}

int main()
{
    
    return 0;
}
