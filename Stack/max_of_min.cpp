#include <bits/stdc++.h>
using namespace std;


/*
    https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
 */
vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n, -1), right(n, n);
    stack<int> s;

    // Find previous smaller element for each index
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            left[i] = s.top();
        s.push(i);
    }

    // Clear the stack for next operation
    while (!s.empty()) s.pop();

    // Find next smaller element for each index
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            right[i] = s.top();
        s.push(i);
    }

    // Array to store results
    vector<int> result(n, INT_MIN);

    // Compute the window size for each element
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1; // Window size
        result[len - 1] = max(result[len - 1], arr[i]);
    }

    // Fill remaining entries
    for (int i = n - 2; i >= 0; i--)
        result[i] = max(result[i], result[i + 1]);

    return result;
}



int main(){
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> result = maxOfMins(arr);

    for (int i = 0; i < result.size(); i++)
        cout << "Max of minimums of subarrays of length " << i + 1 << ": " << result[i] << endl;

    return 0;
}