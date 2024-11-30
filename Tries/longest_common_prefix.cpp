#include <bits/stdc++.h>
using namespace std;

/* 
Longest Common Prefix
=====================

    Method 1 : TC = O(M*N)
               SC = O(1)

    Method 2 : TC = O(M*N)
               SC = O(M*N)
 */

string solve1(vector<string> &arr) {
    if (arr.empty()) return "";

    string ans = "";
    for (int i = 0; i < arr[0].size(); i++) {
        char ch = arr[0][i];
        bool match = true;
        for (int j = 1; j < arr.size(); j++) {
            if (i >= arr[j].size() || arr[j][i] != ch) {
                match = false;
                break;
            }
        }
        if (!match) break;
        ans.push_back(ch);
    }
    return ans;
}

class TrieNode {
public:
    TrieNode* links[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) 
            links[i] = nullptr;
        
        isEnd = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        isEnd = true;
    }

    bool isLeaf() {
        for (int i = 0; i < 26; i++) {
            if (links[i] != nullptr) return false;
        }
        return true;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    string lcp() {
        string ans = "";
        TrieNode* node = root;
        while (!node->isLeaf() && !node->isEnd) {
            int childCount = 0;
            char nextChar;
            TrieNode* nextNode = nullptr;
            for (int i = 0; i < 26; i++) {
                if (node->links[i] != nullptr) {
                    childCount++;
                    nextChar = 'a' + i;
                    nextNode = node->links[i];
                }
            }
            if (childCount == 1) {
                ans.push_back(nextChar);
                node = nextNode;
            } else 
                break;
            
        }
        return ans;
    }
};

string solve2(vector<string> &arr) {
    if (arr.empty()) return "";

    Trie* t = new Trie();
    for (int i = 0; i < arr.size(); i++) {
        t->insert(arr[i]);
    }
    
    return t->lcp();
}

int main() {
    vector<string> arr = {"flower", "flow", "flight"};

    // Test solve1
    string result1 = solve1(arr);
    cout << "Longest Common Prefix (solve1): " << result1 << endl;

    // Test solve2
    string result2 = solve2(arr);
    cout << "Longest Common Prefix (solve2): " << result2 << endl;

    return 0;
}