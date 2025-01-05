#include <bits/stdc++.h>
using namespace std;

/*
Children Sum Property or Check Sum Tree
=====================    ==============


    N = L + R

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


pair <bool,int> solve_util(Node *root){
    if (!root)     return make_pair(1,0);
    if (!root->left && !root->right) return make_pair(1,root->value);
    pair<bool,int> left_ans = solve_util(root->left);
    pair<bool,int> right_ans = solve_util(root->right);
    bool condtion = root->value == left_ans.second + right_ans.second ;
    pair<bool,int> ans ;
    ans.first = left_ans.first && right_ans.first && condtion;
    if (ans.first) ans.second = root->value;
    return ans;;
}

bool solve(Node *root) {
    return solve_util(root).first;
}

int main() {
    // Create a sample binary tree
    Node *root = new Node(10);
    
    root->left = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    root->right = new Node(2);
    root->right->left = new Node(2);

    // Call the solve function
    if (solve(root)) {
        cout << "The tree satisfies the children sum property." << endl;
    } else {
        cout << "The tree does not satisfy the children sum property." << endl;
    }

    // Clean up dynamically allocated memory
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}