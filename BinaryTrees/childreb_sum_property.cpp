#include <bits/stdc++.h>
using namespace std;

/*
Children Sum Property
=====================
(Value at node equal left subtree & right value)
To make it you can +1 any no of times

    Here values of nodes not matter 
    First Node & last node of last level

TC: O(N)
SC: O(N)
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

void solve(Node *root) {
    if (!root) return;
    int child = 0 ;
    if (root->left) child += root->left->value;
    if (root->right) child += root->right->value;
    if (child < root->value) {
        if (root->left) root->left->value = root->value;
        else if (root->right) root->right->value = root->value;
    }
    solve(root->left);
    solve(root->right);
    child = 0;
    if (root->left) child += root->left->value;
    if (root->right) child += root->right->value;
    if (root->left || root->right) root->value = child;
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}
int main() {
    // Constructing the tree
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(9);

    printInorder(root);
    // Calculating the maximum width
    solve(root); cout << endl;
    printInorder(root);


    
    return 0;
}
