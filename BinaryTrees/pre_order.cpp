#include <bits/stdc++.h>
using namespace std;

/* 
PRE ORDER TRAVERSAL    NLR
====================
    Method 1: Recursive 

    Method 2: Using stack


Application 
    Main use of preorder to get copy of tree 
    To generate prefix expression

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


void preorder(Node *curr, vector<int>& arr){
    if (!curr ) return ;

    arr.push_back(curr->value);
    preorder(curr->left, arr);
    preorder(curr->right, arr);
}

void preorder2(Node* root, vector<int>& arr) {
    if (!root) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        arr.push_back(curr->value);
        st.pop();
// Push right child first so that left child is processed first
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform recursive postorder traversal
    vector<int> recursiveResult;
    preorder(root, recursiveResult);
    cout << "Recursive Preorder Traversal: ";
    for (int val : recursiveResult) 
        cout << val << " ";
    
    cout << endl;

    // Perform iterative postorder traversal using two stacks
    vector<int> iterativeResult;
    preorder2(root, iterativeResult);
    cout << "Iterative Preorder Traversal: ";
    for (int val : iterativeResult) 
        cout << val << " ";
    
    cout << endl;

    return 0;
}
/* 







 */