#include <bits/stdc++.h>
using namespace std;

// 3 2 3 4 5 2 2 7 8 5 3 6 4
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int res = 0;

        for (int i: nums){
            while (!st.empty() && st.top() > i)
            st.pop();   
            if (st.empty() || st.top() < i){
                st.push(i);
                res++;
            }
        }
        return res;
    }
};



#define ll long long
int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // int n; cin >> n;

    vector<int>   cookies = {8,15,10};
    int k = 2, mid  = 8;
    Solution s;
    // cout << s.solve(cookies, k, mid) << endl;

    // vector<int> v;

}
/* 

Given an array arr[], where the ith element of arr[] represents the price of a stock on the ith day (all prices are non-negative integers). Find the maximum profit you can make by buying and selling stocks such that after selling a stock, you cannot buy again on the next day (i.e., there is a one-day cooldown).

Examples:

Input: arr[] = [0, 2, 1, 2, 3]
Output: 3
Explanation: You first buy on day 1, sell on day 2 then cool down, then buy on day 4, and sell on day 5. The total profit earned is (2-0) + (3-2) = 3, which is the maximum achievable profit.
Input:  arr[] = [3, 1, 6, 1, 2, 4]
Output: 7
Explanation: You first buy on day 2 and sell on day 3 then cool down, then again you buy on day 5 and then sell on day 6. Clearly, the total profit earned is (6-1) + (4-2) = 7,
*/