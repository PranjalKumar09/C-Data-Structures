#include <bits/stdc++.h>
using namespace std;


/* 

    Assign Cookies
 */

vector<int> greed = {1, 5, 3, 3, 4};
vector<int> cookieSize = {4, 2, 1, 2, 1, 3};

int solve() {
    int m = greed.size(), n = cookieSize.size();
    int l = 0, r = 0;

    sort(greed.begin(), greed.end());
    sort(cookieSize.begin(), cookieSize.end());

    while (l < m && r < n) {
        if (greed[l] <= cookieSize[r]) {  // Fix: should be <=
            l++;  // Child is satisfied
        }
        r++;  // Move to the next cookie
    }
    return l;  // Number of satisfied children
}

int main() {
    cout << "Maximum number of children that can be satisfied: " << solve() << endl;
    return 0;
}
