#include <bits/stdc++.h>
using namespace std;

/*
LCA
=== 
    Immidiate no greater than i/p

    Kth Largest = (n-k+1)th Smallest

    TC: O(H)
    SC: O(1)

    It can be done recursive also but SC increase 
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
Node* LCA(Node* root, int n1, int n2) {
    while (root) {
        // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root->value > n1 && root->value > n2)
            root = root->left;
        // If both n1 and n2 are greater than root, then LCA lies in right
        else if (root->value < n1 && root->value < n2)
            root = root->right;
        else
            break; // Found the LCA
    }
    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    int n1 = 5, n2 = 15;
    Node* lca = LCA(root, n1, n2);
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->value << endl;
    else
        cout << "LCA of " << n1 << " and " << n2 << " doesn't exist" << endl;

    n1 = 25, n2 = 35;
    lca = LCA(root, n1, n2);
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->value << endl;
    else
        cout << "LCA of " << n1 << " and " << n2 << " doesn't exist" << endl;

    n1 = 15, n2 = 25;
    lca = LCA(root, n1, n2);
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->value << endl;
    else
        cout << "LCA of " << n1 << " and " << n2 << " doesn't exist" << endl;

    return 0;
}