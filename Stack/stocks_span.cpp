#include <bits/stdc++.h>

using namespace std;

/* 
STOCKS SPAN

Input: N = 7, price[] = [100 80 60 70 60 75 85]
Output: 1 1 1 2 1 4 6
Explanation: Traversing the given input span for 100 will be 1, 80 is smaller than 100 so the span is 1, 60 is smaller than 80 so the span is 1, 70 is greater than 60 so the span is 2 and so on. Hence the output will be 1 1 1 2 1 4 6.


by using prevgreater by index concept

 */
vector<int> solve(vector<int> &arr){
    vector<int> ans ;
    stack<int> st;
    for (int i = 0 ;  i < arr.size() ; i++){
        while (!st.empty() && arr[st.top()] <= arr[i])  st.pop();
        if (st.empty()) ans.push_back(i+1);
        else ans.push_back((i-st.top()));
        st.push(i);
    }
    return ans;
}



int main() {
    vector<int> arr = {10, 4, 5, 90, 120, 60};
    vector<int> result = solve(arr);
    
    cout << "Result: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}