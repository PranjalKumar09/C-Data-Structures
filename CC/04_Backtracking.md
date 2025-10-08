Generally in palindrome question it is written -> all possible


Word Search L79

class Solution {
    int dir[5] = {0,-1,0,1,0};
    int m, n;
public:
    bool find(vector<vector<char>>& board,int i, int j, int idx, string word){
        if (idx == word.length()) return 1;
        if (0 > i || m -1 < i || 0 > j || n -1 < j || word[idx] != board[i][j]) return 0;
        char ch = board[i][j];
       board[i][j] = '*';

       for (int k = 1; k < 5; k++)
        if (find (board, i+dir[k-1], j+dir[k], idx+1,word)) return true;  
       board[i][j] = ch;

       return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0] && find(board, i, j, 0, word))   return 1;

        

        return 0;  
        
    }
};



Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.



 
class Solution {
    set<vector<int>>  st;
    int n;
    void solve(vector<int> &tmp, int i, vector<int>& num){
        if (i==n){
            if (tmp.size() > 1)
                st.insert(tmp);
            return;
        }

        solve(tmp, i+1, num);

        if (tmp.empty() || tmp.back() <= num[i]){
            tmp.push_back(num[i]);
            solve(tmp, i+1, num);
            tmp.pop_back();
        }
        
    }
public:

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> tmp;
        solve(tmp, 0,nums);
        vector<vector<int>>  ans(st.begin(), st.end());

        return ans;
    }
};







131. Palindrome Partitioning
    class Solution {
    vector<vector<string>> ans;
    int l;
    
    void solve(int i, vector<string>& st, string& s) {
        if (i == l) {
            ans.push_back(st);
            return;
        }
        
        for (int j = i; j < l; j++) {
            string substr = s.substr(i, j - i + 1);
            if (isPalindrome(substr)) {
                st.push_back(substr);
                solve(j + 1, st, s);
                st.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& str) {
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
public:
    vector<vector<string>> partition(string s) {
        l = s.length();
        vector<string> st;
        solve(0, st, s);
        return ans;
    }
};


2305. Fair Distribution of Cookies 
    it looks like this is normal binary sea4ch,but no this is better than backtracking

    class Solution {
    vector<int> children;
    int n;
    int res =INT_MAX;
    void solve(vector<int>& cookies, int k, int idx){
        if (idx == n){
            int t = *max_element(begin(children), end(children));
            res = min(t, res);
            return ;
        }

        for (int i = 0; i < k; i++){
            children[i] += cookies[idx];
            solve(cookies, k, idx+1);
            children[i] -= cookies[idx];
        }
    }
    public:

    int distributeCookies(vector<int>& cookies, int k) {
       children.assign(k, 0);
       n = cookies.size();
       solve(cookies, k, 0);
    return res;
    }
};



1601. Maximum Number of Achievable Transfer Requests
    Its hard looking easy problem 


77. Comhinatoins

class Solution {
    vector<vector<int>>  ans;
    void solve(int n, int k, int idx, vector<int> &t){
        if (t.size() == k) {
            ans.push_back(t);
            return;
        }
        if (idx == n) return;
    
        t.push_back(idx+1);
        solve(n, k, idx+1, t);
        t.pop_back();

        solve(n, k, idx+1, t);
    }
public:
    vector<vector<int>> combine(int n, int k) {
         vector<int> t;
        solve(n, k, 0, t);
        return ans;
    }
};

    tc-> nCk



    void solve2(int n, int k, int idx, vector<int> &t){
        if (t.size() == k) {
            ans.push_back(t);
            return;
        }

        for (int i = idx; i < n; i++){
            t.push_back(i+1);
            solve(n, k, i+1, t);
            t.pop_back();
        }
    }




46. Permutations
    Sorting not matter
    Here we will do ind (0 to n)
    offcouse we will use for for
    Input: nums = [1,2,3]
    
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


    void solve( vector<int> & temp, vector<int>& nums){
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (st.count(nums[i]) == 0){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(temp, nums);
                st.erase(nums[i]);
                temp.pop_back();
            }
             
        }
    }


      void solve2( int idx, vector<int>& nums){
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
    

        for (int i = idx; i < nums.size(); i++){
            swap(nums[i], nums[idx]);
            solve(idx+1, nums);
            swap(nums[i], nums[idx]);
        }
    }


    solve 2 is space optimised, and do from i = idx instead of 0




Tree diagram should be done , 