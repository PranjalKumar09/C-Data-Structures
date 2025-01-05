#include <bits/stdc++.h>
using namespace std;

/* 
POST ORDER TRAVERSAL    LRN
====================
    Method 1: Recursive 

    Method 2: Using two stacks


Application 
    Postfix to delete tree (Before deleting parent , we should delete children first)
    To generate postfix expression

TC & SC in both recursive  & stack is O(N)
 */

class Node{
    public:
    Node *left, *right;
    int value;

    Node(int value){
        this->value = value;
        this->left = this->right = NULL;
    }
};


void postorder(Node *curr, vector<int>& arr){
    if (!curr ) return ;

    postorder(curr->left, arr);
    postorder(curr->right, arr);
    arr.push_back(curr->value);
}

void postorder2(Node* root, vector<int>& arr) {
    if (!root) return;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }

    while (!st2.empty()) {
        Node* curr = st2.top();
        st2.pop();
        arr.push_back(curr->value);
    }
}


int main() {
    // Create a simple tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Perform recursive postorder traversal
    vector<int> recursiveResult;
    postorder(root, recursiveResult);
    cout << "Recursive Postorder Traversal: ";
    for (int val : recursiveResult) {
        cout << val << " ";
    }
    cout << endl;

    // Perform iterative postorder traversal using two stacks
    vector<int> iterativeResult;
    postorder2(root, iterativeResult);
    cout << "Iterative Postorder Traversal: ";
    for (int val : iterativeResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
/* 







 */