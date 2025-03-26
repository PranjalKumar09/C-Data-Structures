#include <bits/stdc++.h>
using namespace std;
/* 
    Insert Interval
    - Insert a new interval into sorted non-overlapping intervals
    - Merge overlapping intervals
    - TC: O(N) (single pass)
    - SC: O(N) (for output vector)
*/

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();

    // Step 1: Add intervals that end before newInterval starts (HANDLING LEFT)
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    // Step 2: Merge overlapping intervals with newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);

    // Step 3: Add remaining intervals (HANDLING RIGHT)
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}



int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> updatedIntervals = insertInterval(intervals, newInterval);

    cout << "Updated Intervals: ";
    for (auto& interval : updatedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}