#include <bits/stdc++.h>
using namespace std;

/*
Kth largest/ smallest
===================== 
    Immidiate no greater than i/p

    Kth Largest = (n-k+1)th Smallest

    TC: O(min(K,N))
    SC: O(min(K,N))
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

Node *KthLargest(Node *root, int& k){
    if (!root) return NULL;
    Node *right = KthLargest(root->right, k);
    if (right) return right;
    k--;
    if (k == 0) return root;
    return KthLargest(root->left, k);
}   
Node *KthSmallest(Node *root, int& k){
    if (!root) return NULL;
    Node *left = KthLargest(root->left, k);
    if (left) return left;
    k--;
    if (k == 0) return root;
    return KthLargest(root->right, k);
}   


int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int k = 3; // Change k to find different kth largest and smallest elements

    Node* kthLargest = KthLargest(root, k);
    if (kthLargest)
        cout << "The " <<" kth largest element is: " << kthLargest->value << endl;
    else
        cout << "The binary search tree does not have " <<" k elements." << endl;

    k = 2; // Change k to find different kth largest and smallest elements

    Node* kthSmallest = KthSmallest(root, k);
    if (kthSmallest)
        cout << "The " <<" kth smallest element is: " << kthSmallest->value << endl;
    else
        cout << "The binary search tree does not have " <<" k elements." << endl;

    return 0;
}