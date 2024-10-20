#include <bits/stdc++.h>
using namespace std;

/* 
Partitioning Palinindrome
=========================


*/
class Solution{
public:
     bool isPalindrome(string s, int start, int end){
        while(start <= end) if (s[start++] = s[end--]) return false;
        return true;
     }

    void solve_util(int index, string s, vector<string> &path, vector<vector<string> > &res){
        if(index == s.length()){
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.length(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                solve_util(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<string> > solve(string s){
        vector<string> path;
        vector<vector<string> > ans;
        solve_util(0 , s, path, ans);
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "aab";
    vector<vector<string>> result = solution.solve(s);

    cout << "Palindromic partitions of " << s << " are:" << endl;
    for (const auto& partition : result) {
        for (const auto& str : partition) 
            cout << str << " ";
        
        cout << endl;
    }

    return 0;
}