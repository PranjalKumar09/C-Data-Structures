#include <bits/stdc++.h>
using namespace std;

/* 
No of Distinct substring
======================== 
    TC = O(n^2)
    SC = O(n^2)
 */
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isEndOfWord; // check if node is the end of a word

    TrieNode(char data) : data(data) {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('/'); // root node with a placeholder character
    }
    void insert_util(TrieNode* root, string word) {
        // TC = O(l) ; length of word
        if (word.length() == 0) {
            root->isEndOfWord = true;
            return;
        }

        int index = word[0] - 'a'; // word will be lowercase
        TrieNode* child;
        if (root->children[index])
            child = root->children[index];
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insert_util(child, word.substr(1));
    }
    void insert(string word) {
        insert_util(root, word);
    }
};

int solve(string &str) {
    Trie trie;
    int count = 0, n = str.length();
    
    for (int i = 0; i < n; i++) {
        TrieNode* current = trie.root;
        for (int j = i; j < n; j++) {
            int index = str[j] - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode(str[j]);
                count++;
            }
            current = current->children[index];
        }
    }
    return count;
}

int main() {
    string str = "banana";
    cout << "Number of distinct substrings: " << solve(str) << endl;
    return 0;
}
