#include <bits/stdc++.h>
using namespace std;

/* 
    Minimum Number of Platforms Needed
    - Find the maximum number of trains at the station at any time
    - TC: O(N log N) (sorting) + O(N) (merging) = O(N log N)
    - SC: O(1)

    If departure is less than arrival than intersection, mean more platform needed
    else less privately needed

*/

vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

int minPlatforms() {
    int n = arrival.size();

    // Step 1: Sort arrival and departure times separately
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;

    // Step 2: Process arrival and departure in order
    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;  // A train arrives, need a new platform
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        } else {
            platforms--;  // A train departs, free a platform
            j++;
        }
    }

    return maxPlatforms;
}

int main() {
    cout << "Minimum Platforms Needed: " << minPlatforms() << endl;
    return 0;
}
