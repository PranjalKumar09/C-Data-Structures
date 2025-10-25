#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);

        for (auto &it: str)
            if (it == '6'){
                it = '9';
                break;
            }
        return stoi(str);
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

