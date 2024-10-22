#include <bits/stdc++.h>
using namespace std;

/*
Count BST node
==============
count bst nodes that lie in given range

TC: O(H+N)
SC: O(N)


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

int solve(Node* root, int low, int high) {
    if (!root) return 0;
    
    // Check if the current node's value falls within the range [low, high]
    if (root->value >= low && root->value <= high) {
        // Count this node and continue to both subtrees
        return 1 + solve(root->left, low, high) + solve(root->right, low, high);
    } else if (root->value < low) {
        // If the current node's value is less than low, skip the left subtree
        return solve(root->right, low, high);
    } else {
        // If the current node's value is greater than high, skip the right subtree
        return solve(root->left, low, high);
    }
}

int main() {
    // Creating a sample BST
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    int low = 7;
    int high = 15;

    // Calling the solve function and printing the result
    int result = solve(root, low, high);
    cout << "Number of nodes with values between " << low << " and " << high << " is: " << result << endl;

    // Cleaning up allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}