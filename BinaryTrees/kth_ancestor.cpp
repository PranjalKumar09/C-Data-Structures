#include <bits/stdc++.h>
using namespace std;

/* 
Kth Ancestor
===========
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

Node* solve_util(Node *root, int& k ,int node){
    if (root == NULL) return root;
    if (root->value == node) return root;
    Node* leftAns = solve_util(root->left, k , node );
    Node* rightAns = solve_util(root->right, k , node );

    if (leftAns && !rightAns) {
        k--;
        if (k<=0){
            k = INT_MAX; // as we have to return ancestor root not target itself
            return root;
        }
        return leftAns;
    }
    if (!leftAns && rightAns) {
        k--;
        if (k<=0){
            k = INT_MAX; // as we have to return ancestor root not target itself
            return root;
        }
        return rightAns;
    }
    return NULL;
}


int solve(Node* root, int k , int node){
    Node* ans = solve_util(root, k, node);
    if (!ans || ans->value == node ) return -1;
    return ans->value;
}


int main() {
    // Creating a sample binary tree:
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

    int k = 2;
    int targetNode = 4;
    int result = solve(root, k, targetNode);
    if (result != -1)
        cout << "The " << k << "-th ancestor of node " << targetNode << " is " << result << endl;
    else
        cout << "The " << k << "-th ancestor of node " << targetNode << " does not exist" << endl;

    // Clean up memory (delete nodes)
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}