#include <bits/stdc++.h>
using namespace std;

/* 
Phone Directory    SC = O(n^2)

===============
    print all suggestion from prifix

    vector<string> &contactList, string &query


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
    
    void getSuggestion_util(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isEndOfWord)
            temp.push_back(prefix);
        for (int i = 0; i < 26; i++) {
            if (curr->children[i]!= NULL)
                getSuggestion_util(curr->children[i], temp, prefix + (char)('A' + i));
        }
    }
    
    vector<vector<string> > getSuggestion(string &str){
        TrieNode* prev = root;
        vector<vector<string> > ans;
        string prefix = "";
        for (int i = 0; i < str.length(); i++) {
            char lastCh = str[i];
            prefix.push_back(lastCh);

            TrieNode* curr = prev->children[lastCh-'A'];
            if (!curr) break;
            vector<string> temp;
            getSuggestion_util(curr, temp, prefix);
            ans.push_back(temp);
            prev = curr;

        }
        return ans;
    }
    bool startsWith(string prefix) {
        return startsWith_util(root, prefix);
    }
};
void solve(vector<string> &arr, string ip){
    Trie *t = new Trie();
<<<<<<< HEAD
    for (int i = 0; i < arr.size(); i++)
=======
    for (int i = 0; i < arr.size(); i++)class TrieNode {
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

>>>>>>> e42b68e (DONE)
        t->insert(arr[i]);
    vector<vector<string> > ans = t->getSuggestion(ip);
    for (int i = 0; i < ans.size(); i++) {
        cout << "Suggestions for prefix \"" << ip.substr(0, i + 1) << "\": ";
        for (string &s : ans[i])
            cout << s << " ";
        cout << endl;
}}

int main() {
    vector<string> arr = {"HELLO", "HEART", "HEAVEN", "HAPPY", "HOUSE"};
    string ip = "HE";
    solve(arr, ip);
    return 0;
}
