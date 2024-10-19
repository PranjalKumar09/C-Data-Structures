#include <bits/stdc++.h>
using namespace std;

/* 
Word Break
==========

    Given: String  S  & word directory
    Goal : Find if  S  can be segmented into words present in dict
    Constraint: Segmented word must present in dict , Can reuse dict words.

    Method 1: Backtracking
        TC : O(2^N)
    Method 2: Memroization
        TC : O( (N^2) * N)
                        for creating substring 
  
 */
class Solution1 { //  recursive
    unordered_set<string> se;
public:
    Solution1(unordered_set<string> s) : se(s) {}

    bool solve1(string &str, int pos) {
        if (pos == str.size()) return true;
        
        string temp = "";
        for (int i = pos; i < str.size(); i++) {
            temp += str[i];
            if (se.find(temp) != se.end()) 
                if (solve1(str, i + 1)) 
                    return true;             
        }
        return false;
    }
};

class Solution2 {
    unordered_set<string> se;
public:
    Solution2(unordered_set<string> s) : se(s) {}

    map<int , bool> mp;
    // this map tells from pos to size no word or combination possible 

    bool solve1(string str, int pos) {
        if (pos == str.size()) return true;
        
        if (mp.count(pos)) return mp[pos];
        string temp = "";
        for (int i = pos; i < str.size(); i++) {
            temp += str[i];
            if (se.find(temp) != se.end()) 
                if (solve1(str, i + 1)) 
                    return mp[pos]= true;
        }
        // by making false it making sure that from pos, pos+1, upto size it cant possible to map  link
        return mp[pos]=false;
    }
};

class Solution3 { // DP 3
    /* 
    0 1   2 3 4 5 6 
    m y | p e n m y
    
     */
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) 
                node->children[c] = new TrieNode();
            
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }
};
class Solution4 {
    Trie trie;

    bool solve1(string str, int pos, vector<int>& memo) {
        if (pos == str.size()) return true;
        if (memo[pos] != -1) return memo[pos];

        TrieNode* node = trie.root;
        for (int i = pos; i < str.size(); i++) {
            if (!node->children[str[i]]) break;
            node = node->children[str[i]];
            if (node->isEndOfWord && solve1(str, i + 1, memo)) 
                return memo[pos] = true;
            
        }
        return memo[pos] = false;
    }

public:
    Solution4(unordered_set<string> s) {
        for (const string& word : s) 
            trie.insert(word);
        
    }

    bool wordBreak(string str) {
        vector<int> memo(str.size(), -1);
        return solve1(str, 0, memo);
    }
};

int main() {
    unordered_set<string> validSubstrings = {"apple", "pen", "applepen"};
    string testString = "applepenapple";

    // Solution 1: Backtracking
    Solution1 sol1(validSubstrings);
    if (sol1.solve1(testString, 0)) 
        cout << "Solution1: The string can be segmented into valid substrings." << endl;
    else 
        cout << "Solution1: The string cannot be segmented into valid substrings." << endl;
    

    // Solution 2: Memoization
    Solution2 sol2(validSubstrings);
    if (sol2.solve1(testString, 0)) 
        cout << "Solution2: The string can be segmented into valid substrings." << endl;
    else 
        cout << "Solution2: The string cannot be segmented into valid substrings." << endl;
    

    // Solution 3: Dynamic Programming
    Solution3 sol3;
    if (sol3.wordBreak(testString, validSubstrings)) 
        cout << "Solution3: The string can be segmented into valid substrings." << endl;
    else 
        cout << "Solution3: The string cannot be segmented into valid substrings." << endl;
    

    // Solution 4: Trie
    Solution4 sol4(validSubstrings);
    if (sol4.wordBreak(testString)) 
        cout << "Solution4: The string can be segmented into valid substrings." << endl;
    else 
        cout << "Solution4: The string cannot be segmented into valid substrings." << endl;
    

    return 0;
}
