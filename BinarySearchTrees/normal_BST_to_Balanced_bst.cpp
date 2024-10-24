#include <bits/stdc++.h>
using namespace std;

/*
Normal BST to Balanced BST
==========================

    find mid => root

    TC: O(N)
    SC: O(1)
*/

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(NULL), right(NULL) {}
};

void inorderTraversal(Node* root, vector<int>& inorderVal) {
    if (!root) return;
    inorderTraversal(root->left, inorderVal);
    inorderVal.push_back(root->value);
    inorderTraversal(root->right, inorderVal);
}


Node* inorderToBST(int s, int e , vector<int>& inorderVal) {
    if (s > e) return NULL;
    int mid = (s + e) / 2;
    Node* root = new Node(inorderVal[mid]);
    root->left = inorderToBST(s, mid - 1, inorderVal);
    root->right = inorderToBST(mid + 1, e, inorderVal);
    return root;
}
Node *solve(Node  *&root){
    vector<int> inorderVal;
    inorderTraversal(root, inorderVal);
    return inorderToBST(0,inorderVal.size()-1,inorderVal);
}
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}
int main() {
    // Constructing a sample unbalanced BST:
    //         10
    //        /  \
    //       5    20
    //      / \     \
    //     1   8     30
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(30);

    cout << "Original BST (Inorder Traversal): ";
    printInorder(root);
    cout << endl;

    // Convert the unbalanced BST to a balanced BST
    Node* balancedRoot = solve(root);

    cout << "Balanced BST (Inorder Traversal): ";
    printInorder(balancedRoot);
    cout << endl;

    // Clean up the dynamically allocated memory for both trees
    delete root->right->right;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    // Clean up the dynamically allocated memory for the balanced tree
    delete balancedRoot->right->right;
    delete balancedRoot->right->left;
    delete balancedRoot->right;
    delete balancedRoot->left->right;
    delete balancedRoot->left->left;
    delete balancedRoot->left;
    delete balancedRoot;

    return 0;
}