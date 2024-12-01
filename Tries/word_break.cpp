#include <bits/stdc++.h>
using namespace std;

/* 
WORD BREAK 
===========

    TC = O(n*m)
    SC = O(n)

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

        int index = word[0] - 'A'; // word will be capital
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

    bool search_util(TrieNode* root, string word) {
        // TC = O(l) ; length of word
        if (word.length() == 0)
            return root->isEndOfWord;

        int index = word[0] - 'A';
        if (root->children[index])
            return search_util(root->children[index], word.substr(1));
        return false;
    }

    bool search(string word) {
        return search_util(root, word);
    }

    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                return false;
            }
        }
        return true;
    }

    TrieNode* remove_util(TrieNode* root, string word, int depth = 0) {
        if (!root)
            return NULL;

        // If the end of the word is reached
        if (depth == word.size()) {
            if (root->isEndOfWord)
                root->isEndOfWord = false;

            // If root doesn't have any children, return NULL
            if (isEmpty(root)) {
                delete root;
                root = NULL;
            }

            return root;
        }

        // Recur for the child corresponding to the next character in the word
        int index = word[depth] - 'A';
        root->children[index] = remove_util(root->children[index], word, depth + 1);

        // If root doesn't have any children and is not the end of another word
        if (isEmpty(root) && !root->isEndOfWord) {
            delete root;
            root = NULL;
        }

        return root;
    }

    void remove(string word) {
        remove_util(root, word);
    }

    bool startsWith_util(TrieNode* root, string prefix) {
        // TC = O(l) ; length of prefix
        if (prefix.length() == 0)
            return true;

        int index = prefix[0] - 'A';
        if (root->children[index])
            return startsWith_util(root->children[index], prefix.substr(1));
        return false;
    }

    bool startsWith(string prefix) {
        return startsWith_util(root, prefix);
    }
};


bool wordBreak(string str, Trie* root) {
    int size = str.length();
    if (!size) return true;

    for (int i = 1; i <= size; i++) {
        if (root->search(str.substr(0, i)) && wordBreak(str.substr(i) , root)) 
            return true;
        
    }
    return false;
}

int main() {
    vector<string> dictionary = {"APPLE", "APPLY", "CAT", "DOG", "DO", "GOD"};
    Trie* trie = new Trie();

    for (string word : dictionary) {
        trie->insert(word);
    }

    string str = "CATDOG";
    if (wordBreak(str, trie)) {
        cout << "The string \"" << str << "\" can be segmented into dictionary words." << endl;
    } else {
        cout << "The string \"" << str << "\" cannot be segmented into dictionary words." << endl;
    }

    str = "CATTIGER";
    if (wordBreak(str, trie)) {
        cout << "The string \"" << str << "\" can be segmented into dictionary words." << endl;
    } else {
        cout << "The string \"" << str << "\" cannot be segmented into dictionary words." << endl;
    }

    delete trie;
    return 0;
}

