
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int k, n;

/*
    MINIMUM COINS


    greedy not works here

*/

// ---------------------------------------
// **1. Recursive Approach (fn1)**
// ---------------------------------------
int fn1(int i, int target) {
    if (target == 0) return 0; // No coins needed for sum 0
    if (i < 0 || target < 0) return INT_MAX; // Invalid case
    
    // Exclude current coin
    int exclude = fn1(i - 1, target);
    
    // Include current coin (if possible)
    int include = INT_MAX;
    if (target >= arr[i]) {
        int subResult = fn1(i, target - arr[i]);
        if (subResult != INT_MAX) include = subResult + 1;
    }

    return min(include, exclude);
}

// ---------------------------------------
// **2. Memoization Approach (fn2)**
// ---------------------------------------
int fn2(int i, int target, vector<vector<int>>& dp) {
    if (target == 0) return 0;
    if (i < 0 || target < 0) return INT_MAX;

    if (dp[i][target] != INT_MAX) return dp[i][target];

    int exclude = fn2(i - 1, target, dp);
    int include = INT_MAX;
    if (target >= arr[i]) {
        int subResult = fn2(i, target - arr[i], dp);
        if (subResult != INT_MAX) include = subResult + 1;
    }

    return dp[i][target] = min(include, exclude);
}

// ---------------------------------------
// **3. Tabulation Approach (fn3)**
// ---------------------------------------
int fn3() {
    vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));

    // Base case: When target is 0, we need 0 coins
    for (int i = 0; i < n; i++) dp[i][0] = 0;

    // Fill the first row separately (using only the first coin)
    for (int j = arr[0]; j <= k; j++) {
        if (j % arr[0] == 0) dp[0][j] = j / arr[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            int exclude = dp[i - 1][j];
            int include = (j >= arr[i] && dp[i][j - arr[i]] != INT_MAX) ? dp[i][j - arr[i]] + 1 : INT_MAX;
            dp[i][j] = min(include, exclude);
        }
    }

    return (dp[n - 1][k] == INT_MAX) ? -1 : dp[n - 1][k];
}

// ---------------------------------------
// **4. Space Optimized Approach (fn4)**
// ---------------------------------------
int fn4() {
    vector<int> prev(k + 1, INT_MAX), curr(k + 1, INT_MAX);

    prev[0] = curr[0] = 0; // Base case

    // Initialize first row
    for (int j = arr[0]; j <= k; j++) {
        if (j % arr[0] == 0) prev[j] = j / arr[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            int exclude = prev[j];
            int include = (j >= arr[i] && curr[j - arr[i]] != INT_MAX) ? curr[j - arr[i]] + 1 : INT_MAX;
            curr[j] = min(include, exclude);
        }
        prev = curr; // Move current row to previous
    }

    return (prev[k] == INT_MAX) ? -1 : prev[k];
}

// ---------------------------------------
// **Main Function**
// ---------------------------------------
void minimumElements() {
    cout << "Recursive: " << (fn1(n - 1, k) == INT_MAX ? -1 : fn1(n - 1, k)) << endl;

    vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
    cout << "Memoization: " << (fn2(n - 1, k, dp) == INT_MAX ? -1 : fn2(n - 1, k, dp)) << endl;

    cout << "Tabulation: " << fn3() << endl;
    cout << "Space Optimized: " << fn4() << endl;
}

int main() {
    arr = {1, 2, 3};
    k = 7;
    n = arr.size();

    minimumElements();

    return 0;
}
