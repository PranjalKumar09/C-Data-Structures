#include <bits/stdc++.h>
using namespace std;

/*
Two Sum in BST
============== 
    Count pairs whoes sun equal to X

    just int count intliaze to 0 ++ when match & at last return 

    i/p : root, k 
                (int at least 1)
    o/p : pairs whoes sum equal to k


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

class BSTIterator {
    stack<Node*> myStack;
    bool reverse;
    void pushAll(Node* node) {
        while (node != NULL) {
            myStack.push(node);
            node = reverse ? node->right : node->left;
        }
    }

public:
    BSTIterator(Node* root, bool reverse) : reverse(reverse) {
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        Node* temp = myStack.top();
        myStack.pop();
        if (reverse)
            pushAll(temp->left);
        else
            pushAll(temp->right);
        return temp->value;
    }
};


bool checkTwoSum(Node* root, int target) {
    if (root == NULL) return false;
    BSTIterator l(root, false), r(root, true);
    int i = l.next(), j = r.next();
    while (i < j) {
        if (i + j == target) return true;
        else if (i + j < target) i = l.next();
        else j = r.next();
    }
    return false;
}

int countPairs(Node* root, int target) {
    if (root == NULL) return 0;
    BSTIterator l(root, false), r(root, true);
    int count = 0;
    int i = l.next(), j = r.next();
    while (i < j) {
        if (i + j == target) {
            count++;
            i = l.next();
            j = r.next();} 
        else if (i + j < target) i = l.next();
        else j = r.next();
    }
    return count;
}

int main() {
    // Constructing a sample BST:
    //         5
    //        / \
    //       3   8
    //      / \ / \
    //     2  4 7  9
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int target = 9;

    // Check if there exist two nodes with the given sum
    if (checkTwoSum(root, target)) 
        cout << "Found two nodes in the BST with sum " << target << endl;
    else 
        cout << "No two nodes in the BST have sum " << target << endl;
    

    // Count the number of pairs with the given sum
    int pairCount = countPairs(root, target);
    cout << "Number of pairs in the BST with sum " << target << " is: " << pairCount << endl;

    // Clean up the dynamically allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
