#include <bits/stdc++.h>
using namespace std;

/*
Check Symmetry Tree
===================

Given a binary tree, check if it is a mirror of itself (ie, symmetric around its center).



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

bool solve_util(Node *left, Node *right){
    if (!left &&!right) return 1;
    if (!left ||!right) return 0;
    if (left->value!= right->value) return 0;
    return solve_util(left->left, right->right) && solve_util(left->right, right->left);
}


bool solve(Node *root){
    if (!root) return 1;
    return solve_util(root->left, root->right);
}
int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    /*
             1
            / \
           2   2
          / \ / \
         3  4 4  3
    */

    // Call the solve function to check if the binary tree is symmetric
    bool isSymmetric = solve(root);

    // Print the result
    if (isSymmetric) {
        cout << "The binary tree is symmetric." << endl;
    } else {
        cout << "The binary tree is not symmetric." << endl;
    }

    // Clean up dynamically allocated memory
    // Add your cleanup code here

    return 0;
}
