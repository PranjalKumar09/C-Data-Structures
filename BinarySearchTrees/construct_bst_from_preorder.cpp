#include <bits/stdc++.h>
using namespace std;

/*
Construct BST from Preorder
===========================

    Method 1: first one node root then insett new upcoming node
        TC: O(N^2) 
        SC: O(1)

    Method 2: 
        Upper bound = INT_MAX;
        TC: O(N^2) 
        SC: O(1)
         

*/
class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(NULL), right(NULL) {}
};
Node* solve(vector<int>& A, int& i, int bound) {
    if (i == A.size() || A[i] >= bound) return NULL;
    Node* root = new Node(A[i++]);
    root->left = solve(A, i, root->value);
    root->right = solve(A, i, bound);
    return root;
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}

void printPreorder(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Preorder traversal of a BST
    vector<int> preorder = {10, 5, 1, 7, 40, 50};
    int index = 0;
    Node* root = solve(preorder, index, INT_MAX);

    // Print the BST to verify it's constructed correctly
    cout << "Inorder Traversal of the BST: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder Traversal of the BST: ";
    printPreorder(root);
    cout << endl;

    // Clean up the dynamically allocated memory for the tree
    // A utility function to delete the tree nodes can be added if needed
    return 0;
}
