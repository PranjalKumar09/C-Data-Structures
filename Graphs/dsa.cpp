#include <bits/stdc++.h>
using namespace std;

int calculate_cost(const string& X, const string& Y, int S, int R, bool start_with_reverse) {
    string Y_rev = Y;
    reverse(Y_rev.begin(), Y_rev.end());

    int count_Y = 0, count_Y_rev = 0;
    int s = 0; // Starting index in X

    string current = start_with_reverse ? Y_rev : Y;

    while (s < X.length()) {
        bool found = false;

        // Try to match substrings of X from position s
        for (int len = X.length() - s; len > 0; len--) {
            if (current.find(X.substr(s, len)) != string::npos) {
                // If a match is found
                found = true;
                if (current == Y) count_Y++;
                else count_Y_rev++;

                // Move s forward by the matched length
                s += len;

                // Toggle between Y and Y_rev
                current = (current == Y) ? Y_rev : Y;
                break; // Found a match, break to start again
            }
        }

        // If no match was found for the current part of X, exit
        if (!found) break;
    }

    return count_Y * S + count_Y_rev * R;
}

int solve(string X, string Y, int S, int R) {
    int cost1 = calculate_cost(X, Y, S, R, false);  // Start with Y
    int cost2 = calculate_cost(X, Y, S, R, true);   // Start with Y_rev
    return min(cost1, cost2);
}

int main() {
    string X = "niveditha";
    string Y = "lavekdahnita";
    int S = 3, R = 5;
    cout << solve(X, Y, S, R) << endl;  // Expected output: 17
    return 0;
}
