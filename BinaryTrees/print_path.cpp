#include <bits/stdc++.h>
using namespace std;

/* 
Print Root to Node Path in Binary Tree
======================================
    TC -> O(N)
    SC -> O(N)
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

bool solve_util(Node *root, vector<int> & arr, int x){
    if (!root) return false;
    arr.push_back(root->value);
    if (root->value == x) return true;
    if (solve_util(root->left, arr, x) || solve_util(root->right, arr, x)) return true;
    arr.pop_back();
    return false;
}


void solve(Node* root, int x){
    vector<int> arr ;
    if (solve_util(root, arr, x)){
        for (int i = 0 ; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    cout << "Element Not Exist" << endl;
}

int main() {
    // Creating a sample binary tree:
    //         10
    //       /    \
    //      1      2
    //     / \    / \
    //    3   4  5   6     
    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    solve(root, 33);

    // Clean up memory (delete nodes)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}

