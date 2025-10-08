#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> mps = {"abc", "def", "ghi", "jkl" ,"mno","pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void solve(int i, string digits, string temp){
        if (i == digits.length()) {
            ans.push_back(temp);
            return;
        }
        int no = digits[i]-'2';
        for (int j = 0; j < mps[no].size(); j++)
        solve(i+1,digits, temp+ mps[no][j]);
        
    }
        
        
public:
    vector<string> letterCombinations(string digits) {
        solve(0, digits, "");
        return ans;
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


