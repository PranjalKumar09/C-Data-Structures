
#include <bits/stdc++.h>

using namespace std;

int solve(int i, vector<int> height){
    if (i < 1) return 0;

    int temp = min(
        abs(height[i] - height[i-1]) + solve(i - 1, height), 
        abs(height[i] - height[i-2] ) + solve(i - 2, height));
cout << i << " " << temp << endl;
    return temp;
}
int solve2(int i, vector<int> &height, vector<int> &mem){
    if (i < 1) return 0;
    if (mem[i] != -1) return mem[i];


    int temp = min(
        abs(height[i] - height[i - 1]) + solve2(i - 1, height, mem),
        abs(height[i] - height[i - 2]) + solve2(i - 2, height, mem));

    return mem[i] = temp;
}
int solve3(vector<int> &height){
    int n = height.size();
    if (n < 1) return 0;
    vector<int> dp(height.size(), 0);

    dp[1] = abs (height[1] - height[0]);
    
    for (int i = 2 ; i < n; i++)
        dp[i] = min(abs(height[i] - height[i - 1]) + dp[i-1],
                    abs(height[i] - height[i - 2]) + dp[i-2]);
    return dp[n-1];
}

int solve4(vector<int> &height)
{
    int n = height.size();
    if (n < 1)
        return 0;
   

    int a = abs(height[1] - height[0]), b = 0;

    for (int i = 2; i < n; i++){
        int temp = min(abs(height[i] - height[i - 1]) + a,
                    abs(height[i] - height[i - 2]) + b);
        b = a;
        a = temp;
        }
    return a;
}

    int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> mem(n, -1);
    // cout << solve (n-1 , height);
    // cout << solve2(n-1, height, mem);
    // cout << solve3( height);
    cout << solve4( height);
}
