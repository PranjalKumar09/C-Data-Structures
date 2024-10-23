#include <bits/stdc++.h>
using namespace std;

/*
Flatten BST to Sorted LL
========================

    1) Do inorder
    2) Make new tree node now make LL also left to NULL
*/

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(NULL), right(NULL) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    LinkedList() : head(NULL), tail(NULL) {}
};

void inorderTraversal(Node* root, LinkedList &list) {
    if (root == NULL) return;

    // Traverse the left subtree
    inorderTraversal(root->left, list);

    // Create a new node and add it to the linked list
    Node* newNode = new Node(root->value);
    if (list.tail) {
        list.tail->right = newNode;
    } else {
        list.head = newNode;
    }
    list.tail = newNode;

    // Traverse the right subtree
    inorderTraversal(root->right, list);
}

Node* flattenBSTToSortedLL(Node* root) {
    LinkedList list;
    inorderTraversal(root, list);
    return list.head;
}

void printLinkedList(Node* head) {
    while (head) {
        cout << head->value << " ";
        head = head->right;
    }
    cout << endl;
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

    Node* head = flattenBSTToSortedLL(root);
    printLinkedList(head);

    // Clean up the dynamically allocated memory for the original tree
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    // Clean up the dynamically allocated memory for the linked list
    while (head) {
        Node* temp = head;
        head = head->right;
        delete temp;
    }

    return 0;
}