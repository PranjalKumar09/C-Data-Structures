#include <bits/stdc++.h>
using namespace std;

/*
Check Balanced Tree
===================

|left_height - right_height| <= 1

Method 1 : B.F. recursive
    TC: O(N^2)

Method 2 : Optimized
    TC: O(N)
    SC: O(1)

*/

class Node {
public:
    Node *left, *right;
    int value;

    Node(int value) {
        this->value = value;
        this->left = this->right = nullptr;
    }
};

int height(Node *root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}

bool solve1(Node *root) {
    if (!root) return true; // Base case should return true for null nodes
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    return solve1(root->left) && solve1(root->right) && diff;
}

int solve2_util(Node *root) {
    if (!root) return 0; // Return 0 for null nodes as they contribute no height
    int left = solve2_util(root->left);
    int right = solve2_util(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}

bool solve2(Node *root) {
    return solve2_util(root) != -1;
}

int main() {
    // Constructing a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Check if the tree is balanced using the first method
    bool isBalanced1 = solve1(root);
    cout << "Is the tree balanced (Method 1)? " << (isBalanced1 ? "Yes" : "No") << endl;

    // Check if the tree is balanced using the second method
    bool isBalanced2 = solve2(root);
    cout << "Is the tree balanced (Method 2)? " << (isBalanced2 ? "Yes" : "No") << endl;

    // Cleaning up memory (optional in competitive programming, but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
