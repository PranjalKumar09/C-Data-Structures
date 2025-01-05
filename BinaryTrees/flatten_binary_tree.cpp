#include <bits/stdc++.h>
using namespace std;

/*
Flatten Binary Tree to LL [Pre Order] 
=========================
(By not creating new memory but rearranging it)

    Method 1: By Recursion
    Method 2: By Stack Iterative
    Method 3: Using Conection here to there Morris Way of preorder
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

void solve2(Node *root){
    stack<Node *> st;
    st.push(root);

    while(!st.empty()){
        Node* cur = st.top(); st.pop();
        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
        if(!st.empty()) cur->right = st.top();
        cur->left = nullptr;
    }
}

void solve3(Node *root){
    Node *cur = root;
    while(cur){
        if(cur->left){
            Node *pre = cur->left;
            while(pre->right) pre = pre->right;
            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}

void print(Node *root){
    while (root){
        cout << " " << root->value;
        root = root->right;
    }
    cout << endl;
}
int main() {
    // Create a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    solve3(root);
    print(root); //  1 2 4 5 3 6 7 

    // Clean up dynamically allocated memory
   

    return 0;
}