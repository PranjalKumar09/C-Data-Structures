#include <bits/stdc++.h>
using namespace std;

/*
Largest BST in BT
================= 

    Method 1:  
        Validate BST -> O(N
        go across every no O(N)*O(N) == O(N^2)
            then no of nodes if valid 
            size -> 1 + x + y
                      left right

    Method 2: 
        Postorder-> left
                    right
                    then node

        (size , minimum , maximum)
*/
class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(NULL), right(NULL) {}
};

class NodeValue {
public:
    int maxNode, minNode, maxSize;
    bool isBST;
    NodeValue() : maxNode(INT_MIN), minNode(INT_MAX), maxSize(0), isBST(true) {}
    NodeValue(int minNode, int maxNode, int maxSize, bool isBST) 
        : minNode(minNode), maxNode(maxNode), maxSize(maxSize), isBST(isBST) {}
};

NodeValue solve_util(Node* root) {
    if (!root) return NodeValue();

    auto left = solve_util(root->left);
    auto right = solve_util(root->right);

    NodeValue ans;
    if (left.isBST && right.isBST && root->value > left.maxNode && root->value < right.minNode) {
        ans.maxNode = max(root->value, right.maxNode);
        ans.minNode = min(root->value, left.minNode);
        ans.maxSize = 1 + left.maxSize + right.maxSize;
        ans.isBST = true;
    } else {
        ans.maxSize = max(left.maxSize, right.maxSize);
        ans.isBST = false;
    }
    return ans;
}

int solve(Node* root) {
    return solve_util(root).maxSize;
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
    // Constructing the binary tree
    /* 
    
        10
       /  \  
      5    15
     /  \   \
    1    8   7
    
     */
    Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(4);
    root->left->left = new Node(6);
    root->left->right = new Node(8);
    // root->right->right = new Node(7);

    // Finding the largest BST in the binary tree
    int sizeOfLargestBST = solve(root);

    cout << "Size of the largest BST in the binary tree: " << sizeOfLargestBST << endl;

    // Clean up the dynamically allocated memory for the tree
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}




