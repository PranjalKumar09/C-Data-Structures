#include <bits/stdc++.h>
using namespace std;

/*
Check for Dead End 
===================
leaf node where insertion not possible


*/

class Node {
public:
    int value;
    Node* left, *right;
    Node(int value) {
        this->value = value;
        this->left = this->right = NULL;
    }
};

bool isDeadBST(Node* root, int minValue, int maxValue) {
    // If the current node is null, return false
    if (!root) 
        return false;

    // If the range of values for the current subtree is collapsed to a single value,
    // then it's considered a dead BST
    if (minValue == maxValue) 
        return true;

    // Recursively check left and right subtrees with updated range values
    return isDeadBST(root->left, minValue, root->value - 1) ||
           isDeadBST(root->right, root->value + 1, maxValue);
}

int main() {
    // Example usage
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(9);

    // Check if the BST is dead
    bool result = isDeadBST(root, INT_MIN, INT_MAX);
    
    // Output the result
    if (result)
        cout << "The BST is dead." << endl;
    else
        cout << "The BST is not dead." << endl;
    
    return 0;
}
