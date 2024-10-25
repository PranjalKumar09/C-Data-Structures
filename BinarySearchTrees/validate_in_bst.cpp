#include <bits/stdc++.h>
using namespace std;

/*
Validate BST
===========
    Immidiate no greater than i/p

    Method 1: Inorder Traversal -> boolean type fn 
        TC: O(N)
        SC: O(H)
    Method 2: By range checking by max, min
        TC -> O(N)
        SC -> O(1)
*/

class Node {
public:
    int value;
    Node* left, *right;
    Node(int data) {
        this->value = data;
        this->left = this->right = nullptr;
    }
};

bool solve_util(Node* root, int min , int max){
    if (!root) return true;
    if (root->value < min || root->value > max) return false;
    return solve_util(root->left, min, root->value - 1) && solve_util(root->right, root->value + 1, max);
}

bool solve2(Node* root) {
    return solve_util(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    // Uncomment the following line to make the tree invalid
    // root->right->left->value = 6;

    bool isBST = solve2(root);
    if (isBST)
        std::cout << "The given binary tree is a binary search tree." << std::endl;
    else
        std::cout << "The given binary tree is not a binary search tree." << std::endl;

    return 0;
}
