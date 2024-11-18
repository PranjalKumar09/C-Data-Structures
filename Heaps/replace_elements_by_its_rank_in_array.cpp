#include <bits/stdc++.h>
using namespace std;

/*  
Replace elements by its Rank in Array
=====================================
    i/p: 20  15  26  2  98  6
    o/p:  4   3   5  1  6   2

    Method 1: B.F.
        T.C. -> O(N^2)
        S.C. -> O(N)

    Method 2: O.S.
        T.C. -> O(N) + O(N log N) + O(N)
        S.C. -> O(2N)

*/

void solve(vector<int> & arr){
    map<int, int> mp;
    int n = arr.size();
    int temp = 1;
    vector<int> brr(n) ;
    for (int i = 0; i < n ; i++)
        brr[i] = arr[i];
    sort(brr.begin(), brr.end());
    for (int i = 0; i < n ; i++){
        mp[brr[i]] = temp;
        temp++;
    }
    for (int i = 0; i < n ; i++)
        cout << mp[arr[i]] << " ";
}


int main() {
    vector<int> nums = {20,15,26,2,98,6};
    solve(nums);

    return 0;
}


