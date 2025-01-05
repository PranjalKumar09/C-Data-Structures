#include <bits/stdc++.h>
using namespace std;

/* 
Top View
========

    if (mpp.find(line)==mpp.end())
        mpp[line]=node->data;

*/

// Node structure for the binary tree
class Node {
public:
    int val;
    Node *left, *right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};


vector<int> solve(Node *root) {
    vector<int> ans;
    if (!root) return ans; 
    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line  = it.second; // level
        if (mpp.find(line)== mpp.end())
            mpp[line] = node->val;
        if (node->left) q.push({node->left, line-1});
        if (node->right) q.push({node->right, line+1});
    }
    for (auto it : mpp)
        ans.push_back(it.second);
    return ans;



}


int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    /*
             1
            / \
           2   3
            \
             4
              \
               5
                \
                 6
    */

    // Call the solve function for top view
    vector<int> result = solve(root);

    // Print
    cout << "Top View of the Binary Tree:" << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;






    return 0;
}
