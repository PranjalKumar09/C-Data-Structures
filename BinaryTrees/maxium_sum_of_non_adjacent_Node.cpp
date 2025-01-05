#include <bits/stdc++.h>
using namespace std;

/* 
Maxium Sum of non-adjacent Node
===============================

    <a , b>
    a-> MaxSum by exluding current
    b-> MaxSum by including current
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

pair<int,int> solve_util(Node *root){
    if (!root) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> leftAns = solve_util(root->left);
    pair<int,int> rightAns = solve_util(root->right);
    pair<int,int> ans;
    ans.first = root->value  + leftAns.second + rightAns.second;
    ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
    return ans;
}


int solve(Node* root){
    pair<int, int> ans = solve_util(root);
    return max(ans.first, ans.second);
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

    int result = solve(root);
    cout << "The maximum sum of non-adjacent nodes is: " << result << endl; // 10 + (3 + 4) + (5 + 6) => 10 + 7 + 11 

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

