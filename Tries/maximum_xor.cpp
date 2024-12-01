#include <bits/stdc++.h>
using namespace std;

/* 
Maximum XOR
===========
    
We will use trie (this will like BT)


We will convert decimal to binary
We will found either 0 or 1 
Check for both if not go with what you have


Choosing the Opposite Bit:

    At each bit position, if the current bit of the number we're evaluating is 0, we look for a 1 in the Trie to make the XOR result 1 for that position.
    Conversely, if the current bit is 1, we look for a 0 in the Trie.

Maximizing XOR:

    By selecting the opposite bit (1 - bit), we try to ensure that the XOR result at that bit position is 1.
    If the opposite bit is not available in the Trie, we fall back to the same bit, which results in a 0 for that bit position in the XOR result.

    TC = O(N*32)
    SC = O(N)

     */

class TrieNode {
public:
    TrieNode* children[2];
    
    TrieNode() {
        children[0] = children[1] = nullptr;
    }
    
    bool containsKey(int bit) {
        return children[bit];
    }
    
    TrieNode* get(int bit) {
        return children[bit];
    }
    
    void put(int &bit, TrieNode *node) {
        children[bit] = node;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) 
                node->put(bit, new TrieNode());
            
            node = node->get(bit);
        }
    }

    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) { // due to xor property we choosing oopposite 
                maxXOR = maxXOR | (1 << i);
                node = node->get(1 - bit);
            } else 
                node = node->get(bit);
            
        }
        return maxXOR;
    }
};
int solve(vector<int>& nums) {
    Trie* trie = new Trie();
    for (int num : nums) 
        trie->insert(num);
    
    int maxXOR = INT_MIN;
    for (int num : nums) {
        maxXOR = max(maxXOR, trie->findMaxXOR(num));
    }
    return maxXOR;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR is: " << solve(nums) << endl;
    return 0;
}