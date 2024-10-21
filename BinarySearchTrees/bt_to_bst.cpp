#include <bits/stdc++.h>
using namespace std;

/*
BT to BST
=========
    make inorder vector
    sort it
    theb construct bst form that
*/

class Node {
public:
    int value;
    Node* left, *right;
    Node(int data) {
        this->value = data;
        this->left = this->right = NULL;
    }
};

void inorderTraversal(Node* root, vector<int>& inorder) {
    if (!root) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->value);
    inorderTraversal(root->right, inorder);
}

// Function to replace node values during inorder traversal with sorted values
void replaceValues(Node* root, vector<int>& sortedValues, int& index) {
    if (!root) return;
    replaceValues(root->left, sortedValues, index);
    root->value = sortedValues[index++];
    replaceValues(root->right, sortedValues, index);
}

// Function to convert a binary tree to a binary search tree
void BTtoBST(Node* root) {
    // Step 1: Perform inorder traversal and collect node values
    vector<int> inorder;
    inorderTraversal(root, inorder);

    // Step 2: Sort the collected values
    sort(inorder.begin(), inorder.end());

    // Step 3: Replace node values during inorder traversal with sorted values
    int index = 0;
    replaceValues(root, inorder, index);
}


// Helper function to print inorder traversal of a tree
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}

int main() {
    // Constructing the binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    // Convert binary tree to binary search tree
    BTtoBST(root);

    // Print inorder traversal of the resulting BST
    cout << "Inorder traversal of the constructed BST:" << endl;
    printInorder(root);
    cout << endl;

    // Clean up the dynamically allocated memory for the tree
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
