#include <bits/stdc++.h>

using namespace std;
/* 
SUM OF MAXIMUM - MINIMUM SUBARRAYS IN ARRAY

Method 1: by using prevGreates , prevSmaller
Method 2:
 */
int solve(vector <int> & arr){
    int ans = 0;
    for (int i = 0 ; i < arr.size() ; i ++){\
        int mini = INT_MAX,  maxi = INT_MIN;
        for (int j = i+1 ; j < arr.size() ; j++){
            mini = min(mini, arr[j]);
            maxi = max(maxi, arr[j]);
            ans += maxi - mini;
        }
    }
    return ans;
}

int main() {
    // Test case 1
    vector<int> arr1 = {3,1,2,4};
    cout << "Test case 1 result: " << solve(arr1) << endl; // Output: 4

    // Test case 2
    vector<int> arr2 = {4, 3, 2, 1};
    cout << "Test case 2 result: " << solve(arr2) << endl; // Output: 10

    // Test case 3
    vector<int> arr3 = {1, 3, 2};
    cout << "Test case 3 result: " << solve(arr3) << endl; // Output: 4

    return 0;
}