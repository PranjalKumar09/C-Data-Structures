#include <bits/stdc++.h>
using namespace std;

/* 
    Non-Overlapping Intervals
    - Remove the minimum number of intervals to make them non-overlapping
    - TC: O(N log N) (sorting) + O(N) (iteration) = O(N log N)
    - SC: O(1)
*/

vector<vector<int>> intervals = {{1, 3}, {2, 4}, {3, 5}, {6, 8}, {7, 9}};

int eraseOverlapIntervals() {
    if (intervals.empty()) return 0;

    // Step 1: Sort by ending time
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];  // Sort by end time
    });

    // Step 2: Use Greedy approach to select non-overlapping intervals
    int count = 0, last_end = INT_MIN;

    for (auto &interval : intervals) {
        if (interval[0] >= last_end) {  
            // No overlap → update last_end
            last_end = interval[1];
        } else {
            // Overlap → Remove this interval
            count++;
        }
    }

    return count;  // Minimum intervals to remove
}

int main() {
    cout << "Minimum Intervals to Remove: " << eraseOverlapIntervals() << endl;
    return 0;
}
