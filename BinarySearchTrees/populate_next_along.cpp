#include <bits/stdc++.h>
using namespace std;

/*
Populate Next along with left / right or inorder successor
==========================================================
    TC : O(N)
    SC : O(1) 

*/

class Node {
public:
    int value;
    Node* left;
    Node* next;
    Node* right;
    Node(int v) : value(v), left(NULL), right(NULL) {}
};

void solve(Node* root, Node*& next) {
    if (root) {
        // First set the next pointer in right subtree
        solve(root->right, next);

        // Set the next as previously visited Node in reverse Inorder
        root->next = next;

        // Change the next for subsequent Node
        next = root;

        // Finally, set the next pointer in left subtree
        solve(root->left, next);
    }
}

void printNextPointers(Node* root) {
    if (root) {
        printNextPointers(root->left);
        cout << "Node " << root->value << ": " << (root->next ? to_string(root->next->value) : "NULL") << endl;
        printNextPointers(root->right);
    }
}

int main() {
    // Constructing the binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    // Populate the next pointer for each node in the binary tree
    Node* next = NULL;
    solve(root, next);

    // Print the next pointer of each node to verify the result
    cout << "Next pointers of each node in the binary tree:" << endl;
    printNextPointers(root);

    // Clean up the dynamically allocated memory for the tree
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}


