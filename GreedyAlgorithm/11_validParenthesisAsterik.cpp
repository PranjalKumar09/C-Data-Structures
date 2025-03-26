#include <bits/stdc++.h>
using namespace std;

/* 
    Valid Parenthesis String (with `*`)
    - `*` can be `(`, `)`, or empty
    - TC: O(N)
    - SC: O(1)

    Its recursion complexity is 3^n
    TC & SC in dp will O(N^2)
 */

bool checkValidString(string s) {
    int low = 0, high = 0;

    for (char c : s) {
        if (c == '(') {
            low++;
            high++;
        } else if (c == ')') {
            low = max(0, low - 1);
            high--;
        } else {  // If '*'
            low = max(0, low - 1);  // Assume it is `)`
            high++;  // Assume it is `(`
        }

        if (high < 0) return false;  // More `)` than possible `(`, invalid case
    }

    return low == 0;  // All `(` must be closed
}

int main() {
    string s = "(*)";
    cout << (checkValidString(s) ? "Valid" : "Invalid") << endl;
    
    return 0;
}
