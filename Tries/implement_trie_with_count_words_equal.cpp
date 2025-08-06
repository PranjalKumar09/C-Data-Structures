#include <bits/stdc++.h>
using namespace std;

/* 
Implement Trie with countWordsEqual Words starting with, erase to, insert
===========================================================================

    trie {
        links[26]
        ew = 0      end word
        cp = 0      count prefix


Insert

apple    a       p         p         l      e
      ew = 0   ew = 0   ew = 0   ew = 0   ew = 1
      cp = 0   cp = 1   cp = 1   cp = 1   cp = 1

applee   a       p         p         l      e        e
      ew = 0   ew = 0   ew = 0   ew = 0   ew = 1  ew = 2
      cp = 0   cp = 2   cp = 2   cp = 2   cp = 2  cp = 1

Erase
reduce

 */


struct Node {
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void reduceEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }

    int getEnd() {
        return cntEndWith;
    }

    int getPrefix() {
        return cntPrefix;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKey(word[i])) 
                return 0;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containKey(prefix[i])) 
                return 0;
            node = node->get(prefix[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKey(word[i])) 
                return;
            node->reducePrefix();
            node = node->get(word[i]);
        }
        node->reduceEnd();
    }
};

int main() {
    Trie trie;

    string word1 = "apple";
    string word2 = "app";
    string word3 = "applause";

    trie.insert(word1);
    trie.insert(word2);
    trie.insert(word3);

    cout << "Count words equal to 'apple': " << trie.countWordsEqualTo(word1) << endl;
    cout << "Count words starting with 'app': " << trie.countWordsStartingWith(word2) << endl;

    trie.erase(word1);
    cout << "After erasing 'apple':" << endl;
    cout << "Count words equal to 'apple': " << trie.countWordsEqualTo(word1) << endl;
    cout << "Count words starting with 'app': " << trie.countWordsStartingWith(word2) << endl;

    return 0;
}