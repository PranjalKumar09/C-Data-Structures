#include <bits/stdc++.h>
using namespace std;

/* 
Lowest Common Ancestor (LCA)
============================
    (last intersection point from top)
    i/p : *node n1, n2   : any two element

    Found in either left or right subtree

    if found in left subtree, return left subtree


    SC => O(N)
    TC => O(N)
 */


class Node{
    public:
    Node *left, *right;
    int value;

    Node(int value){
        this->value = value;
        this->left = this->right = NULL;
    }
};




Node *lca(Node *root , int n1 , int n2){
    if (!root || root->value == n1 || root->value == n2)
        return root;
    
    Node* Left = lca(root->left, n1, n2);
    Node* Right = lca(root->right, n1, n2);
    if (!Left) return Right;
    if (!Right) return Left;
    return root;
}

int main() {
    // Creating a sample binary tree:
    //        3
    //       / \
    //      5   1
    //     / \ / \
    //    6  2 0  8
    //      / \
    //     7   4
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    int n1 = 5, n2 = 1;
    Node* ancestor = lca(root, n1, n2);
    if (ancestor)
        std::cout << "LCA of " << n1 << " and " << n2 << " is " << ancestor->value << std::endl;
    else
        std::cout << "LCA not found" << std::endl;

    // Clean up memory (delete nodes)
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}