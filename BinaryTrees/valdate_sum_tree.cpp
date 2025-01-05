#include <bits/stdc++.h>
using namespace std;

/* 
Validate Sum Tree
=================

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
    if (!root) return 0;
    int ls = solve(root->left);
    int rs = solve(root->right);
    if (ls==-1||rs==-1)return -1;
    if (!root->left && !root->right || rs+ls == root->value)return root->value;
    return -1;
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
    Node* root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(1);
    root->right->right = new Node(6);
    root->left->left->left = new Node(3);
    root->right->right->right = new Node(6);

    cout <<  solve(root) << endl;// return root-L=>value is sum tree
    return 0;
}



