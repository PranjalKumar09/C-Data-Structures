#include <bits/stdc++.h>
using namespace std;

/*
Basics of BINARY SEARCH TREES
=============================

    B.T. used to optimized the operation of searching an element among Tree Node

    For Every Node      
        for Left : node -> data < root
        for Right: node -> data > root
     _________________________________
    | Left Child < Node < Right Child |
    ----------------------------------

    In BST ideally , duplicate nodes not allowed
    Every subtree is BST in it self
    Max Height is in order log(N)
        In skewed Tree in order of N
    In order of tree is sorted

    Duplicate Representation like :    8  8
                                       |/   \
                                       3    10
                                      /       \
                                     1        11

    Insertion => O(log(N))
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
Node* insert(Node* root, int data) {
    if (!root) {
        root = new Node(data);
        return root;
    }
    if (data < root->value)
        root->left = insert(root->left, data);
    else if (data > root->value)
        root->right = insert(root->right, data);
    return root;
}

void INPUT(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insert(root, data);
        cin >> data;
    }
}


int main() {
    Node* root = nullptr;
    INPUT(root);
    // Now you can use the root node for further operations.
    return 0;
}