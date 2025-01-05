#include <bits/stdc++.h>
using namespace std;

/* 
Transform to Sum Tree
=====================

    we have to return int sum 
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

int solve(Node* root ){
    if (root)
    return root->value+solve(root->left)+solve(root->right);
    return 0;
}



int main() {
    // Creating a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    //   /         \
    //  7           8
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->right->right->right = new Node(8);

    cout << "Sum is " << solve(root);//3
    return 0;
}



