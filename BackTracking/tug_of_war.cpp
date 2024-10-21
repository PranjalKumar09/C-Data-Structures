#include <bits/stdc++.h>
using namespace std;

/* 
Tug of War
========== 

    Devide input arr in 2 part (n/2 size) such that absolute minimum possible

    arr1 = sum1
    arr2 = total - sum1 = sum2


    TC: 0(2^n)
    SC: O(n)


 */


void solve_util(vector<int>& arr, int n, vector<bool>& cur, int select, vector<bool>& sol, int& min_diff, int sum1, int sum2, int pos) {
    if (pos == n || (n/2 - select) > (n - pos)) {
        return;
    }

    if (select == n / 2) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (cur[i]) sum1 += arr[i];
            else sum2 += arr[i];
        }
        int diff = abs(sum1 - sum2);
        if (diff < min_diff) {
            min_diff = diff;
            sol = cur;
        }
        return;
    }

    cur[pos] = true;
    solve_util(arr, n, cur, select + 1, sol, min_diff, sum1 + arr[pos], sum2, pos + 1);
    cur[pos] = false;  // Backtrack here

    solve_util(arr, n, cur, select, sol, min_diff, sum1, sum2 + arr[pos], pos + 1);
}

void tug_of_war(vector<int>& arr) {
    int n = arr.size();
    vector<bool> cur(n, false);
    vector<bool> sol(n, false);
    int min_diff = INT_MAX;

    solve_util(arr, n, cur, 0, sol, min_diff, 0, 0, 0);

    cout << "The minimum difference is " << min_diff << endl;
    cout << "Subset 1: ";
    for (int i = 0; i < n; i++) {
        if (sol[i]) cout << arr[i] << " ";
    }
    cout << "\nSubset 2: ";
    for (int i = 0; i < n; i++) {
        if (!sol[i]) cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}; // Example array
    tug_of_war(arr);
    return 0;
}