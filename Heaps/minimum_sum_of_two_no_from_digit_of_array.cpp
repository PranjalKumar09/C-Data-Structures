#include <bits/stdc++.h>
using namespace std;

/*  
Minimum sum of two no formed from difit of an array
==================================================

    i/p : { 6 , 8 , 4 , 5 , 2 , 3}
    o/p :  604
          (358, 246)
*/

int solve(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        (i & 1) ? a = a*10 + arr[i] : b = b*10+arr[i];
    }
    return a+b;
}
int main() {


    vector<int> arr = { 6 , 8 , 4 , 5 , 2 , 3};
    cout << solve(arr);

    return 0;
}


