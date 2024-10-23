#include <bits/stdc++.h>
using namespace std;

/*
Inorder Predecessor/Sucessor
============================

    Inorder: 1 2 3 4 5 6 7 8 9 10
    Val->8
        Predecessor->7
        Sucessor->9
    TC: O(N)
    SC: O(1)
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


Node *Successor(Node *root){
    Node *successor = root;
    while(root){
        if (successor->value <= root->value)
            root = root->left;
        else {
            successor = root;
            root = root->right;
        }
    }
    return successor;
}   

Node *predecessor(Node *root){
    Node *predecessor = root;
    while(root){
        if (predecessor->value >= root->value)
            root = root->right;
        else {
            predecessor = root;
            root = root->left;
        }
    }
    return predecessor;
}


int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int k = 3;

 
    Node* successor = Successor(root->left);
    if (successor)
        cout << "The successor of " << root->left->value << " is: " << successor->value << endl;
    else
        cout << "No successor found for " << root->left->value << endl;

    Node* predecessorNode = predecessor(root->right);
    if (predecessorNode)
        cout << "The predecessor of " << root->right->value << " is: " << predecessorNode->value << endl;
    else
        cout << "No predecessor found for " << root->right->value << endl;

    return 0;
}