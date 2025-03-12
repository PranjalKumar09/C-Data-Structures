#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;



/* 
NEXT GREATER ELEMENT IN CIRCULAR ARRAY
======================================


i/p: 3, 10, 4 , 2 , 1 , 2 , 6 . 1 , 7 , 2 ,9
o/p: 10,-1, 6 , 6 , 2 , 6 , 7 . 7 , 9 , 9 ,10
 */

void print_stack(stack<int> stack){
    while (!stack.empty()){
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}



void solve(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 2*n - 1; i >= 0 ; i--){
    // cout << " =========================== " << endl <<  "nums[i%n] " << nums[i%n] <<  "  | ";
        // print_stack(st);
        while (!st.empty() && st.top() <= nums[i%n])
            st.pop();
        if (!st.empty() && i<n) ans[i]=st.top();
        st.push(nums[i%n]);    }
    nums = ans;
    }

void print_array(vector<int> &arr){
    for (int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << " ";
    cout << endl;
}



int main() {
    vector <int> ip = {2,1,5,6,2,3,1};
    print_array(ip);
    solve(ip);
    print_array(ip);

    return 0;
}
