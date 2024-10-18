#include <bits/stdc++.h>
using namespace std;

/* 
Remove Invalid Parenthesis
==========================

    By removing minimum no of parenthesis

    i/p : "()())()"
    o/p : "(())()"
          "()()()"
        (no duplication)
    
    TC: O(2^n)
 */

int find_removal(string& ip){
    stack<char> st;
    for(int i  = 0; i < ip.length(); i++){
        if (ip[i] == '(')    st.push('(');
        else {
            if(!st.empty() && st.top()=='(') st.pop();
            else st.push(')');
        }
    }
    return st.size();
}
void solve_util(string ip,  vector<string> &ans, unordered_map<string, bool> & mp, int removals){
    if (mp[ip]) return; // stops from multiple chuking
    mp[ip]=1;
    if (removals==0) {
        int removal_needed  = find_removal(ip); // chec
        if (removal_needed == 0) ans.push_back(ip);
        return;
    }
    for(int i = 0; i < ip.length(); i++){
        string left_part = ip.substr(0, i);
        string right_part = ip.substr(i+1);
        solve_util(left_part + right_part, ans, mp, removals-1); // remove one parenthesis
    }
    return;
}


vector<string> solve(string& ip){
    unordered_map <string , bool> mp;
    int min_removal = find_removal(ip);
    vector <string> ans;
    solve_util(ip, ans, mp, min_removal);
    return ans;
}

int main(){
    string ip = "()())()";
    vector<string> res = solve(ip);
    cout << "Valid Parenthesis Combinations are: \n";
    for(auto &s : res) cout << s << "\n";
    return 0;

}
