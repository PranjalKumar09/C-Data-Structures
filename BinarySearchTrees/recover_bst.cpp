#include <bits/stdc++.h>
using namespace std;

/*
Recover BST
===========
    Two nodes swapped 
    i/p: BST

    Method 1:  Inorder Traversal
        Sort it (N log N) correct order
        Tranverse order

        TC: O(2N + NlogN)
        SC: O(N)

    Method 2: Swapped Nodes -> Adjacent / Not adjacent

        TC : O(N)
        SC : O(1) by morris other wise O(N)

        Inorder not storing it 
        i-1 < i
*/

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(NULL), right(NULL) {}
};
Node* first, *previous, *middle, *last; // Member variables
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    if (previous && (root->value < previous->value)) { // violation
        // 1st violation
        if (!first) {
            first = previous;
            middle = root;
        } else {
            last = root;
        }
    }
    previous = root;
    inorder(root->right);
}

void solve(Node* root) {
    first = middle = last = NULL;
    previous = new Node(INT_MIN);
    inorder(root);
    if (first && last) 
        swap(first->value, last->value);
    else if (first && middle) 
        swap(first->value, middle->value);
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}

void printPreorder(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Construct a BST with two swapped nodes
    Node* root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    cout << "Inorder Traversal of the original tree: ";
    printInorder(root);
    cout << endl;

    // Recover the BST
    solve(root);

    cout << "Inorder Traversal of the recovered tree: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder Traversal of the recovered tree: ";
    printPreorder(root);
    cout << endl;

    // Clean up the dynamically allocated memory for the tree
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}




