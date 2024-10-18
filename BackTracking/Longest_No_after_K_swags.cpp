#include <bits/stdc++.h>
using namespace std;

/* 
    Longest string after K swaps
    ============================
*/
void solve(string str, int k, string& maxStr, int ctr) {
    int n = str.size();
    
    // Base case: no swaps left or reached the end of the string
    if (k == 0 || ctr == n) return;

    char maxm = str[ctr];

    // Find the maximum character in the remaining string
    for (int j = ctr + 1; j < n; j++) {
        if (str[j] > maxm) {
            maxm = str[j];
        }
    }

    // Only reduce k if there's a higher character to swap
    if (maxm != str[ctr]) k--;

    // Try all characters from the end of the string to ctr
    for (int j = n - 1; j >= ctr; j--) {
        if (str[j] == maxm) {
            // Swap to bring the highest character to the current position
            swap(str[j], str[ctr]);

            // Check if the current string is the largest found so far
            if (str > maxStr) {
                maxStr = str;
            }

            // Recur for the next position
            solve(str, k, maxStr, ctr + 1);

            // Backtrack to restore the original string
            swap(str[j], str[ctr]);
        }
    }
}



int main() {
    string str = "123";
    int k = 1;

    string maxStr = str;
    solve(str, k, maxStr, 0);

    cout << "Maximum lexicographic string representation after at most " << k << " swaps is: " << maxStr << endl;

    return 0;
}
