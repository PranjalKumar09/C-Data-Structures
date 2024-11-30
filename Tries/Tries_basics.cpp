#include <bits/stdc++.h>
using namespace std;

/* 
Basics of Tries
===============

    Tries word itself comes from word retrival
    
    Trie is type of K-ary search tree used for storing & serarching  specific key from set. Using Trie, search comlplexities can be brought to optimal limit (Key length)

    Multiway tree data data structure

    Pattern matching efficiently (prefix matching)\

    Can have multiple branches

    O(M) -> Maximum tree length
        any key can searched in O(m) time

    Characters act as children 
    
    If character not found by letter then it creat itself


        Root Node
       /         \
      a           d
     /           / \
    n           a   o
   / \         /   (do)
  d   t       d
(and) (ant)  dad




remove string -> search string do last character (termianal node)    isEndOfWord = False



Why tree, not hashmap >
            additonal memory for same preficx it is also hard process prefix type question
    
    Trie use storage in optimal way
    Trie will/can show storage

<<<<<<< HEAD
 */
=======


Print Unique togerther -> Insert in treee the print tree

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

>>>>>>> e42b68e (DONE)
int main() {
    Trie* trie = new Trie();
    trie->insert("APPLE");
    trie->insert("APPLY");

    cout << "Search APPLE: " << trie->search("APPLE") << endl;
    cout << "Search APPLY: " << trie->search("APPLY") << endl;

    cout << "StartsWith APP: " << trie->startsWith("APP") << endl;
    cout << "StartsWith APPL: " << trie->startsWith("APPL") << endl;
    cout << "StartsWith APL: " << trie->startsWith("APL") << endl;

    trie->remove("APPLE");
    cout << "After removing APPLE:" << endl;
    cout << "Search APPLE: " << trie->search("APPLE") << endl;
    cout << "Search APPLY: " << trie->search("APPLY") << endl;

    delete trie;
    return 0;
}