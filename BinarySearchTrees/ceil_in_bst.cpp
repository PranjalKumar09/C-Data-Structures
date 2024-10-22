#include <bits/stdc++.h>
using namespace std;

/*
Ceil in BST
===========
    Immidiate no greater than i/p

    TC -> O(log N)
    wrost -> O(1)
*/

class Node {
public:
    int value;
    Node* left, *right;
    Node(int data) {
        this->value = data;
        this->left = this->right = NULL;
    }
};
int solve(Node* root, int target) {
    int ceil = -1;
    while (root) {
        if (root->value == target)
            return target;
        else if (root->value < target)
            root = root->right;
        else {
            ceil = root->value;
            root = root->left;
        }
    }
    return ceil;
}
int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int target = 6;

    int result = solve(root, target);
    cout << "Ceiling of " << target << " is: " << result << endl;

    return 0;
}
