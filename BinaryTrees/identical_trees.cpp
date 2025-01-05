#include <bits/stdc++.h>
using namespace std;

/*
Identical Trees
===============


    TC: O(N)
    SC: O(N)

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

bool solve(Node *root1 , Node *root2) {
    if (!root1 && !root2 ) return true; 
    if (!root1 || !root2) return false;
    return root1->value == root2->value && solve(root1->left, root2->left) && solve(root1->right, root2->right);
}

int main() {
    // Constructing the first binary tree
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    // Constructing the second binary tree
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);

    // Check if the two trees are identical
    bool areIdentical = solve(root1, root2);
    cout << "Are the two trees identical? " << (areIdentical ? "Yes" : "No") << endl;

    root2->right->right->value = 6;
    areIdentical = solve(root1, root2);
    cout << "Are the two trees identical? " << (areIdentical ? "Yes" : "No") << endl;


    // Cleaning up memory (optional in competitive programming, but good practice)
    delete root1->left->left;
    delete root1->left->right;
    delete root1->right->left;
    delete root1->right->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->left;
    delete root2->left->right;
    delete root2->right->left;
    delete root2->right->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;

}
