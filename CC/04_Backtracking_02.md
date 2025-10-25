

3149. Find the Minimum Cost Array Permutation


    Input: nums = [1,0,2]
    Output: [0,1,2]
|perm[0] - nums[perm[1]]| + |perm[1] - nums[perm[2]]| + ... + |perm[n - 1] - nums[perm[0]]|




    We have to seleect lexiographically smallest one
        soltuion for above one is
            [0,1,2] -> |0 - nums[1]| + |1 - nums[2]| + |2 - nums[0]|
            [2,0,1] -> |2 - nums[0]| + |0 - nums[1]| + |1 - nums[2]|
            [1,2,0] -> |1 - nums[2]| + |2 - nums[0]| + |0 - nums[1]|


    so offcouse we will 0, 1, 2, 
        starting with 0, we can keep visied, any search every possible


1255. Maximum Score Words Formed by Letters
    its easy recursion

In interview dont say directly recusion, instead try first thing coming of solution

When in intreview they ask can you memorize your recusion
    never say yes directly , (like , yes as it is recusion)


    instead say like , if tree diagram of recusion contain then its possible, then move to tree diagram 


//S.C : O(n)
class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1])
                continue; //ignore duplicate elements
            curr.push_back(candidates[i]);
            solve(candidates, target-candidates[i], curr, result, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); //because we will ignore duplicate elements
        solve(candidates, target, curr, result, 0);
        return result;
    }
};


1593 Split a String Into the Max Number of Unique Substrings 



class Solution {
    int l, ans = 1;

    void solve(int idx, string &str, unordered_set<string> &st) {
        if (idx == l) {
            ans = max(ans, (int)st.size());
            return;
        }

        if (st.size() + l - idx <= ans) return;

        for (int i = idx; i < l; i++) {
            string cur = str.substr(idx, i - idx + 1);
            if (st.count(cur)) continue;  // ✅ skip duplicates

            st.insert(cur);
            solve(i + 1, str, st);
            st.erase(cur);
        }
    }

public:
    int maxUniqueSplit(string s) {
        l = s.length();
        unordered_set<string> st;
        solve(0, s, st);
        return ans;
    }
};




1718. Construct the Lexicographically Largest Valid Sequence

class Solution {
    int l;
    vector<int>  ans;
    vector<bool>  vis;

    bool solve(int idx, int n){
    while (idx < l && ans[idx]) idx++;  
        if (idx == l)
        return true;;
    
        for (int i = n; i  > 0; i--){
            if (!vis[i-1] && !ans[idx] && (i == 1 || (idx+i < l && !ans[idx+i]))){
                vis[i-1] = 1;
                ans[idx] = i;

                if (i != 1) ans[idx+i] = i;
                
                if (solve(idx+1, n)) return 1;
                ans[idx] = vis[i-1] = 0;

                if (i!=1) ans[idx+i] = 0;
            }
        }

        return 0;
    }
    public:
    
    vector<int> constructDistancedSequence(int n) {
        this-> l = (n-1)*2+1;
        ans.assign(l, 0);
        vis.assign(n, 0);
        solve(0, n);
        return ans;
    }
};

this while loop is one of best thing i ever seen in recusrion   



1079. Letter Tile Possibilities

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int count = 0;
    vector<int> freq;
    void solve(string str){
        count++;

        for (int i  = 0; i < 26; i++)
            if (freq[i]){
                freq[i]--;
                char ch = i + 'A';
                string str2 = str+ch;
                solve(str+ch);
                freq[i]++;
            }
    }
public:
    int numTilePossibilities(string tiles) {
        freq.assign(26, 0);
        for (auto &it: tiles)
            freq[it-'A']++;
        
            solve("");
        
        return count-1;
    }   
};


1415. The k-th Lexicographical String of All Happy Strings of Length n

