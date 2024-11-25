/*
Steps:
    (1) Build TRIE using all words of word_dict
    (2) Backtrack for all possible valid positions and store all valid sentences

    root -> '/' 
    tc = O(N.len(String) +2^M)
    M = len(S)

    wrost case -> ('a' , 'aa', 'aaa', 'aaaa')





  */
class Solution {
public:
    vector<string> ans;

    struct trienode {
        char c;
        int we;
        trienode *child[26];
        trienode(char c) {
            we = 0;
            this->c = c;
            for (int i = 0; i < 26; i++) child[i] = NULL;
        }
    };

    trienode *root;
    
    void breakWord(string s) {
        trienode *curr = root;
        int idx;
        for (int i = 0; i < s.length(); i++) {
            idx = s[i] - 'a';
            if (curr->child[idx] == NULL)
                curr->child[idx] = new trienode(char(97 + idx));
            curr = curr->child[idx];
        }
        curr->we += 1;
    }
    
    bool searchInTrie(string s) {
        trienode *curr = root;
        int idx;
        for (int i = 0; i < s.length(); i++) {
            idx = s[i] - 'a';
            if (curr->child[idx] == NULL)
                return false;
            curr = curr->child[idx];
        }
        return curr->we > 0; // Ensure it's a word end
    }
    
    void solve(string &s, string st, int pos) {
        if (pos == s.length()) {
            st.pop_back(); // Remove the last space
            ans.push_back(st);
            return;
        }
        for (int i = pos; i < s.length(); i++) {
            if (searchInTrie(s.substr(pos, i - pos + 1))) {
                solve(s, st + s.substr(pos, i - pos + 1) + " ", i + 1);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new trienode('/');
        for (int i = 0; i < wordDict.size(); i++)
            breakWord(wordDict[i]);
        
        solve(s, "", 0);
        // Clean up memory
        deleteTrie(root);
        
        return ans;
    }
    
    void deleteTrie(trienode *node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) 
            if (node->child[i]) 
                deleteTrie(node->child[i]);

        
        delete node;
    }
};
