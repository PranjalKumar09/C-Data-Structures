#include <bits/stdc++.h>
using namespace std;

/* 
COUNT NO OF LEAF NODE
=====================
 (can be solved by many traversals . Here solved by inorder )
 i/p : *root 
 o/p : count
 _______________
 |int cnt = 0;  |
 |fn(root,cnt); |
 |return cnt;   |
 ----------------
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


void fn(Node *root, int &count){
    if (!root) return;
    fn(root->left, count);
    if (!root->left && !root->right) count++;
    fn(root->right, count);
}

int main() {
    // Create a simple tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    

    int cnt = 0;
    fn(root, cnt);
    cout << "Number of leaf nodes: " << cnt << endl;
   

    return 0;
}