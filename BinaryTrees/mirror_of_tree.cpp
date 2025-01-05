#include <bits/stdc++.h>
using namespace std;

/*
Miroor of Tree
==============

i/p: 
      5
  3      6
2   4
Preorder: 2 3 4 5 6


o/p:
      5
  6      3
        4  2
Preorder: 6 5 4 3 2


    TC : O(N)
    SC : O(N)
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

void print(vector<int>  &arr){
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inorder(Node *curr, vector<int>& arr) {
    if (!curr) return;
    inorder(curr->left, arr);
    arr.push_back(curr->value);
    inorder(curr->right, arr);
}

Node* solve(Node *root) {
    if (!root) return root;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    if (root->left) solve(root->left);
    if (root->right) solve(root->right);
    return root;
}

int main() {
    // Create a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> traversal;

    // In-order traversal of the original tree
    inorder(root, traversal);
    cout << "In-order traversal of the original tree: ";
    print(traversal);

    // Call the solve function to mirror the tree
    solve(root);

    // Clear the traversal vector and do an in-order traversal of the mirrored tree
    traversal.clear();
    inorder(root, traversal);
    cout << "In-order traversal of the mirrored tree: ";
    print(traversal);

    // Clean up dynamically allocated memory
    delete root->right->right;  // original left->left
    delete root->right->left;   // original left->right
    delete root->right;         // original left
    delete root->left->right;   // original right->right
    delete root->left->left;    // original right->left
    delete root->left;x           // original right
    delete root;

    return 0;
}