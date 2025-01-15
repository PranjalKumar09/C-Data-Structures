#include <bits/stdc++.h>

using namespace std;

/*
    Frog Jump with K steps


 */

int solve(int i, vector<int> &height, int k)
{
    if (i < 1)
        return 0;

    int temp = INT_MAX;
    for (int j = 1; -1 < i - j  && j <= k; j++)
     temp = min(temp, abs(height[i] - height[i - j]) + solve(i - j, height, k));
    return temp;
}
int solve2(int i, vector<int> height, vector<int> mem, int k)
{
    if (i < 1)
        return 0;
    if (mem[i] != -1) return mem[i];

    int temp = INT_MAX;
    for (int j = 1; -1 < i - j  && j <= k; j++)
    temp = min(temp, abs(height[i] - height[i - j]) + solve(i - j, height, k));
    return mem[i] = temp;
}
int solve3( vector<int> &height, int k)
{    
    int n = height.size();
    if  (n < 1 ) return 0;
    vector<int> mem (n, INT_MAX);
    mem[0] = 0;


    for (int i = 1; i < n; i++) 
        for (int j = 1; j <= k && -1 < i-j; j++)
            mem[i] = min(mem[i], abs(height[i] - height[i - j]) + mem[i - j]);
    
    
    return mem[n-1];
}




int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> mem(n, -1);
    // cout << solve (n-1 , height, k);
    // cout << solve2(n-1, height, mem, k);
    // cout << solve3( height, k);
    // cout << solve4(height);
}
