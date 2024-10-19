#include <bits/stdc++.h>
using namespace std;

/* 
    Is K partition of Subset with equal Sum possible
    =================================================
*/

bool isPossible(vector<int> &arr, vector<int> &subsetSum, vector<bool> &taken, int subset, int k, int n,  int curIdx, int limitIdx){

    if (subsetSum[curIdx]==subset) { // curIdx range -> 0 to k-1
        if (curIdx==k-2) return 1;
        return isPossible(arr, subsetSum, taken, subset, k, n, curIdx+1, n-1);
    }


    for(int i = limitIdx; i >= 0; i--){
        if (taken[i]) continue;
        int tmp = subsetSum[curIdx] + arr[i];
        if (tmp <= subset){
            taken[i] = 1;
            
            subsetSum[curIdx]+= arr[i];
            if (isPossible(arr, subsetSum, taken, subset, k, n, curIdx, i-1)) return true;

            subsetSum[curIdx] -= arr[i];
            taken[i] = false;
        }
    }
    return false;
}

bool solve(int k , vector<int> &arr){
    int n = arr.size();
    if (k == 1) return 1;
    if (n < k) return false;

    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    if (sum % k!= 0) return false;

    int subset = sum/k;
    vector<int> subsetSum(k,0);
    vector<bool> taken(n, false);
    subsetSum[0] = arr[n-1];
    taken[n-1] = 1;

    return isPossible(arr, subsetSum, taken, subset, k , n, 0 , n-1);
}


int main() {
    int k = 3; 
    vector<int> arr = {4, 3, 2, 3, 5, 2, 1};  // sum 20 -> 21/3 = 7   , 

    // Call the solve function
    if (solve(k, arr)) {
        cout << "The array can be partitioned into " << k << " subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into " << k << " subsets with equal sum." << endl;
    }

    return 0;
}
