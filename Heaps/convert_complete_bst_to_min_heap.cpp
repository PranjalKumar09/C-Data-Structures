#include <bits/stdc++.h>
using namespace std;

/* 
Convert Complete BST to Min Heap
=============================== 
*/

class Node {
public:
    int value;
    Node *left;
    Node *right;
    Node(int val) {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void inorderTraversal(Node *curr, vector<int> &inorder){
    if (!curr) return;
    inorderTraversal(curr->left, inorder);
    inorder.push_back(curr->value);
    inorderTraversal(curr->right, inorder);
}

void BSTtoHeap(Node* root,  vector<int> &arr, int &index){
    if (!root) return;
    root->value = arr[++index];
    BSTtoHeap(root->left, arr, index);
    BSTtoHeap(root->right, arr, index);
}
void preorder(Node *root){
    if (!root) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}
void solve(Node *root){
    vector<int> ans;
    int i = -1;
    inorderTraversal(root, ans); 
    BSTtoHeap(root,ans,i);
    preorder(root);
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(18);
    preorder(root); cout << endl;

    solve(root);
}

