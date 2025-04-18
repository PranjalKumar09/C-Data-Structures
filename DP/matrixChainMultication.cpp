#include <bits/stdc++.h>
using namespace std;

/*
    PARTITION DP - MATRIX CHAIN MULTIPLICATION

    * Core Idea: Solve one partition first, then the other, and combine results.
    
    Example Setup:
    ---------------------------------
    Given matrices:
    A = 10x20, B = 20x30, C = 30x40, D = 40x50

    Matrix multiplication options:
    - (AB)C or A(BC)  
    Though results are mathematically the same, computation costs differ.

    Example Costs:
    A = 10x30, B = 30x5, C = 5x60  
    - (AB)C = 10×30×5 + 10×5×60 = 4500  
    - A(BC) = 10×30×60 + 30×5×60 = 27000  
    Hence, the order matters for minimizing operations.

    Matrix Chain setup:
    arr[] -> {10, 20, 30, 40, 50}
    N = 5 (4 matrices with dimensions derived from arr)

    Matrix dimensions:
    - A -> 10x20
    - B -> 20x30
    - C -> 30x40
    - D -> 40x50  
    Dimensions: A[i-1] * A[i]

    ---------------------------
    Partition Approach:
    1. Start with the entire block -> indices (i, j)
       Example:
       (ABCD)
       i-------j
       Try different partitions:
       (AB)(CD) | (A)(BCD) | (ABC)(D)
        i k j    i  k j     i  k j

    2. Loop through all partitions (`k` between i and j)
    3. Return the minimum cost among all valid partitions.

    --------------------------------
    Time Complexity Analysis:
    Each partition has ~N ways, and we calculate the cost recursively for each subproblem:
    TC -> O(N * N * N) = O(N^3)
*/

// Matrix dimensions array
vector<int> arr = {10, 20, 30, 40, 50};
int n = arr.size();

// Recursive Solution - Basic (Exponential Time)
int f(int i, int j) {
    if (i >= j) return 0; // Base case: Single matrix or invalid

    int min_val = INT_MAX;

    // Try all partitions between i and j
    for (int k = i; k < j; k++) {
        int cost = f(i, k) + f(k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        min_val = min(min_val, cost);
    }

    return min_val;
}

// Memoized Version - Top-Down DP (O(N^2) states)
    int f2(int i, int j, vector<vector<int>>& dp) {
    if (i >= j) return 0; // Base case
    if (dp[i][j] != -1) return dp[i][j]; // Return cached result if available

    int min_val = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = f2(i, k, dp) + f2(k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        min_val = min(min_val, cost);
    }

    return dp[i][j] = min_val; // Store and return
}

// Tabulated Version - Bottom-Up DP (O(N^3) time, O(N^2) space)
int f3() {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Start filling from smaller chains to larger ones
    for (int i = n - 1; i > 0; i--) { // i goes from n-1 to 1 (reverse order)
        for (int j = i + 1; j < n; j++) { // j starts from i+1 to n-1
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + 
                 dp[k + 1][j] +
                 arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1]; // The final result
}

int main() {
    // Basic Recursive Solution
    cout << "Recursive Solution: " << f(1, n - 1) << endl;

    // Memoized Solution
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoized Solution: " << f2(1, n - 1, dp) << endl;

    // Bottom-Up DP Solution
    cout << "Bottom-Up DP Solution: " << f3() << endl;

    return 0;
}
