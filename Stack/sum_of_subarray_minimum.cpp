#include <bits/stdc++.h>
using namespace std;

/* 
SUM OF SUBARRAY MINIMUMS

i/p : arr , o/p : int

sum of minimums forma all siubarray possible (contingous)

    BF => 
        TC :  O(n^3) 



Optimize:
    
    previ smaller for lowest = 0
    next smaller for out of range = n-1

Now one thing here in one we should use strictly greater , and other greater or equal this to prevent duplicating
        
 */



void next_smaller(const vector<int>& arr, vector<int>& right) {
    int n = arr.size();
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
}

void previous_smaller(const vector<int>& arr, vector<int>& left) {
    int n = arr.size();
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}

int solve(const vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);

    previous_smaller(arr, left);
    next_smaller(arr, right);

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int count = (i - left[i]) * (right[i] - i); // note both multipying term will +ve
        ans = (ans + arr[i] * count) ;
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    int result = solve(arr);
    cout << "Sum of minimums of all subarrays: " << result << endl;
    return 0;
}       