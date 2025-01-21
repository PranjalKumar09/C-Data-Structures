#include <bits/stdc++.h>

using namespace std;

/*
    Maximum sum of non - adjacent elements
        pick or non pick concept 

 */

int solve(int i,vector<int> &arr)
{
    if (i < 0)
        return 0;
    return max(
        arr[i] + solve(i-2, arr),
        solve(i-1, arr));
}

int solve2(int i,vector<int> &arr, vector<int> &mem)
{
    if (i < 0)
        return 0;
    if (mem[i] != -1) return mem[i];
    
    return mem[i] =  max(
        arr[i] + solve2(i-2, arr, mem),
        solve2(i-1, arr, mem));
}

int solve3(vector<int> &arr)
{   
    int n  = arr.size();

    // if (mem[i] != -1) return mem[i];
    vector<int> mem(n, 0);
    
    mem[0] = arr[0];
    
    if (n == 1) return mem[0];
    mem[1] = max ( arr[0],  arr[1]);

    for (int i = 2; i < n; i++){
    mem[i] =  max(arr[i] + mem[i-2],mem[i-1]);
        }

    return mem[n-1];
}
int solve4(vector<int> &arr)
{   
    int n  = arr.size();
    if (n == 1) return arr[0];

    int a = arr[0],  b = max ( a,  arr[1]);

    for (int i = 2; i < n; i++){
        int temp =  max(arr[i] + a,b);
        a = b;
        b = temp;
        }

    return b;
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();

    
    vector<int> mem(n, -1);
    // Call the solve function and print the result
    // cout << solve(n-1, arr);
    // cout << solve2(n-1, arr, mem);
    // cout << solve3(arr);
    cout << solve4(arr);

}
