#include <bits/stdc++.h>
using namespace std;

/*
Deletion
========
    TC -> O(H)
    wrost -> O(N)
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


Node *solve(Node* root,int target){
    if (!root) return nullptr;
    if (root->value == target){
        // 0 child
        if (!root->left && !root->right){
            delete root;
            return nullptr;
            }
        // 1 child
        if (root->right && !root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left && root->right){
            root->value = root-> right->value; 
            root->right = solve(root->right,root->value);
            return root;
                 }
    }
    else if (root-> value > target){
        root->left = solve(root->left,target);
        return root;
    }
    root->right = solve(root->right,target);
    return root;
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->value << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    int target = 3;
    root = solve(root, target);

    cout << "Inorder traversal after deletion of " << target << ": ";
    inorder(root);
    cout << endl;

    return 0;
}