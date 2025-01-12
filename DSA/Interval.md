
#### **1. Insert Interval**
**Type**: Interval Manipulation (Merge Intervals)

**Problem**: Insert a new interval into a sorted list of non-overlapping intervals and merge any overlapping intervals.

**Approach**:
1. **Before Overlap**: Add intervals that end before the new interval starts.
2. **Merge Overlaps**: Combine overlapping intervals by updating the `start` and `end` of the new interval.
3. **After Overlap**: Add remaining intervals that start after the new interval ends.
4. **Return Result**: Combine all intervals into the result list.

**Key Steps**:
- Use a pointer `s` to traverse intervals.
- Check and merge intervals using `min()` and `max()` to adjust `newInterval`.

**Code Skeleton**:
```cpp
vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> ans;
    int s = 0, n = intervals.size();

    // Add intervals before overlap
    while (s < n && intervals[s][1] < newInterval[0])
        ans.push_back(intervals[s++]);

    // Merge overlapping intervals
    while (s < n && intervals[s][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[s][0], newInterval[0]);
        newInterval[1] = max(intervals[s++][1], newInterval[1]);
    }
    ans.push_back(newInterval);

    // Add intervals after overlap
    while (s < n)
        ans.push_back(intervals[s++]);

    return ans;
}
```


Minimum no of interval to remove such that no Overlap
``` cpp
int minRemoval(vector<vector<int>>& intervals) {
        // Sort intervals based on the starting time
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        int ans = 0;
        int end = intervals[0][1];  // Store the end time of the first interval
        
        // Iterate over intervals starting from the second interval
        for (int i = 1; i < n; i++) {
            // If the current interval starts before the previous one ends
            if (intervals[i][0] < end) {
                ans++;  // Increment removal count
                // We keep the interval with the smaller end time (greedy choice)
                end = min(end, intervals[i][1]);
            } else {
                // No overlap, so just update the end time to the current interval's end
                end = intervals[i][1];
            }
        }
        
        return ans;
}
```