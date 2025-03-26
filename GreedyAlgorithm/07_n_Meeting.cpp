#include <bits/stdc++.h>
using namespace std;

/* 
    N Meetings in One Room (Greedy Algorithm)
    TC: O(2N + N log N) ≈ O(N log N)
    SC: O(3N) (for storing start, end, and sorting indices)
*/

vector<int> start = {1, 3, 0, 5, 8, 5};
vector<int> end_time = {2, 4, 5, 7, 9, 9};

int maxMeetings() {
    int n = start.size();

    // Step 1: Store meeting index along with start and end times
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({end_time[i], start[i]});  // Sort by end time
    }

    // Step 2: Sort meetings by end time
    sort(meetings.begin(), meetings.end());

    // Step 3: Select meetings greedily
    int count = 1;  // First meeting always gets selected
    int last_end = meetings[0].first;

    for (int i = 1; i < n; i++) {
        if (meetings[i].second > last_end) {  // If meeting starts after last selected meeting
            count++;
            last_end = meetings[i].first;
        }
    }

    return count;
}

int main() {
    cout << "Maximum Meetings: " << maxMeetings() << endl;
    return 0;
}
