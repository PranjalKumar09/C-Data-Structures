#include <bits/stdc++.h>

using namespace std;


/* 
    House Robber
        Similar to MaxSumNonAdjacentElement problem
        but here it is circular array and array can contain negative element

    so we can do max(arr(0--n-2) ,  arr(1 --n-1))

 */
int solve(int i, vector<int> &arr)
{
    if (i < 0)
        return 0;
    return max(
        arr[i] + solve(i - 2, arr),
        solve(i - 1, arr));
}

int solve2(int i, vector<int> &arr, vector<int> &mem)
{
    if (i < 0)
        return 0;
    if (mem[i] != -1)
        return mem[i];

    return mem[i] = max(
               arr[i] + solve2(i - 2, arr, mem),
               solve2(i - 1, arr, mem));
}

int solve3(vector<int> &arr)
{
    int n = arr.size();

    // if (mem[i] != -1) return mem[i];
    vector<int> mem(n, 0);

    mem[0] = arr[0];

    if (n == 1)
        return mem[0];
    mem[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        mem[i] = max(arr[i] + mem[i - 2], mem[i - 1]);
    }

    return mem[n - 1];
}
int solve4(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];

    int a = arr[0], b = max(a, arr[1]);

    for (int i = 2; i < n; i++)
    {
        int temp = max(arr[i] + a, b);
        a = b;
        b = temp;
    }

    return b;
}
int robStreet(vector<int> &arr)
{
    int n = arr.size();
    vector<int> arr1 = arr, arr2 = arr;
    arr1.erase(arr1.begin());
    arr2.pop_back();


    // return max(solve(n-2,arr1),solve(n-2, arr2));
    
    // vector<int> mem1(n-1, -1), mem2(n-1, -1);
    // return max(solve2(n-2,arr1, mem1),solve2(n-2, arr2, mem2));

    // return max(solve3(arr1), solve3(arr2));
    return max(solve4(arr1), solve4(arr2));
}

int main()
{


    vector<int> arr{1, 5, 1, 2, 6};
    cout << robStreet(arr);
 
}
