#include <bits/stdc++.h>
using namespace std;

/*
Min & Max in BST
================
    TC -> O(H)
    SC -> O(H)
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


int minVal(Node* root){
    if (root->left) return minVal(root->left);
    return root->value;
} 

int maxVal(Node* root){
    if (root->right) return maxVal(root->right);
    return root->value;
}


int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout << minVal(root) << endl;
    cout << maxVal(root) << endl;
    return 0;
}