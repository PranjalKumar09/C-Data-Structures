#include <bits/stdc++.h>
using namespace std;

/* 
Duplicate Subtree in BT size more than 2
========================================
    o/p: bool
    store in map string, count enter dollar in empty node

     */

class Node {
    public:
    int value;
    Node* left, *right;
    Node(int value) {
        this->value = value;
        this->left = this->right = NULL;
    }
};

class Solution {
private:
    unordered_map<string, int> mp;

    string solve(Node* root) {
        if (!root) return "$";
        string s = to_string(root->value);
        if (!root->left && !root->right) return s;
        string left = solve(root->left);
        string right = solve(root->right);
        s = s + left + right;
        if (s.length() > 3) {// Ensure the serialized string length is greater than 3 (to represent size more than 2)
            cout << s << endl;
            mp[s]++;}
        return s;
    }

public:
    bool dupSub(Node* root) {
        mp.clear(); // Clear the map before each call
        solve(root);
        for (auto it : mp) {
            if (it.second > 1) return true;
        }
        return false;
    }
};

// Helper function to create a new Node
Node* newNode(int value) {
    Node* temp = new Node(value);
    return temp;
}

// Main function to test the Solution
int main() {
    // Creating a binary tree for testing
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(2);
    root->right->right->left = newNode(4);

    Solution sol;
    if (sol.dupSub(root))
        cout << "The binary tree has duplicate subtrees of size more than 2." << endl;
    else
        cout << "The binary tree does not have duplicate subtrees of size more than 2." << endl;

    return 0;}