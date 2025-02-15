#include <bits/stdc++.h>
using namespace std;

/*
    LONGEST INCREASING SUBSEQUENCE
 */

vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
int n = arr.size();

// Recursive approach (Brute Force) for Longest Increasing Subsequence
int f(int i, int prev) {
    if (i >= n) return 0;

    int take = 0;
    if (prev == -1 || arr[i] > arr[prev])
        take = 1 + f(i + 1, i);

    int not_take = f(i + 1, prev);

    return max(take, not_take);
}

// Memoization approach for Longest Increasing Subsequence
int f2(int i, int prev, vector<vector<int>>& dp) {
    //     vector<vector<int>> dp(n, vector<int>(n , -1));

    //  dp[2][0] means LIS from index 2 with no previous element (prev = -1)

    if (i >= n) return 0;
    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

    int take = 0;
    if (prev == -1 || arr[i] > arr[prev])
        take = 1 + f2(i + 1, i, dp);

    int not_take = f2(i + 1, prev, dp);

    return dp[i][prev + 1] = max(take, not_take);
}

// Bottom-up Dynamic Programming approach (Tabulation)
int f3() {
    // second value +  1 always, 


    vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) 
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
            int take = 0;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                take = 1 + dp[ind + 1][ind+1];
// here [ind+1][ind+1] used instead of ind + 1][ind] , because here previous indexing changes
// dp[ind + 1][ind]: Wrong, as it implies prev_ind = ind - 1, not ind.

            int not_take = dp[ind + 1][prev_ind + 1];

            dp[ind][prev_ind + 1] = max(take, not_take);
        }

    return dp[0][0];
}

// Optimized Bottom-up DP approach with reduced space complexity (2 rows)
int f4() {
    vector<int> curr(n + 1, 0), prev(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
            int take = 0;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                take = 1 + prev[ind + 1];

            int not_take = prev[prev_ind + 1];

            curr[prev_ind + 1] = max(take, not_take);
        }
        prev = curr;
    }

    return curr[0];
}

int f5() {
    vector<int> dp(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
        for (int prev_ind = -1; prev_ind <= ind - 1; prev_ind++) {  // Reversed loop
            int take = 0;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                take = 1 + dp[ind + 1];
            int not_take = dp[prev_ind + 1];
            dp[prev_ind + 1] = max(take, not_take);
        }
    return dp[0];
}

int fn6(){

    vector<int> dp(n, 1);
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int prev = 0; prev < i; prev++) {
            if (arr[i] > arr[prev] && dp[i] < dp[prev] + 1)
                dp[i] = dp[prev] + 1;
            maxi = max(maxi, dp[i]);
        }
    }
    return maxi;
}




void f7() {
    // p[i] means: dp[i] is the LIS length ending at index i.
    vector<int> dp(n, 1), hash(n, -1);
    for (int i = 1; i < n; i++) {   
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
    }
    // Find the index with maximum dp value
    int max_len = 0, start = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > max_len) {
            max_len = dp[i];
            start = i;
        }
    }
    // Reconstruct the sequence
    vector<int> lis;
    int index = start;
    while (index != -1) {
        lis.push_back(arr[index]);
        index = hash[index];
    }
    reverse(lis.begin(), lis.end());
    cout << "LIS sequence: ";
    for (int num : lis) cout << num << " ";
    cout << endl;
}

int f8(){
/*
    Longest Increasing Subsequence using Binary Search (BS)

    longest increasing subsequence
    1 7 8 4 5 6 -1 9

    i/p -> 1 , 7, 8     === > 1 7 8
    i/p -> 4            === > 1 4 8
    i/p -> 5            === > 1 4 5
    i/p -> 6            === > 1 4 5 6
    i/p -> -1           === >-1 4 5 6
    i/p -> 9            === >-1 4 5 6 9

 */

    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > temp[len - 1]) {
            temp.push_back(arr[i]);
            len++;
        } else {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;

    // TEMPORARY is not lis
}


int main() {
    cout << f(0, -1) << endl;
    vector<vector<int>> dp(n, vector<int>(n , -1));
    cout << f2(0, -1, dp) << endl;
    cout << f3() << endl;
    cout << f4() << endl;
    cout << f5() << endl;
    
    // Call f6 to print the LIS
    f6(); 
}
