#include <bits/stdc++.h>
using namespace std;

/*
Boundary Traversal   
===================
(Anti Clock Wise Traversal)

    Part 1 : Left exluding leaf
    Part 2 : Leaf Node left to right
    Part 3 : Reverse right node exluding leaf node

TC = O(H) +  O(H) + O(N)
SC = O(N)
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

void print(vector<int>  &arr){  
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " " ;
    cout << endl;
}

bool isLeaf(Node *root){
    return !root->left && !root->right;
}

void addLeftBounary(Node *root, vector<int> &res){
    Node *cur = root->left;
    while (cur){
        if (!isLeaf(cur)) res.push_back(cur->value);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRightBounary(Node *root, vector<int> &res){
    Node *cur = root->right;
    vector<int> temp;
    while (cur){
        if (!isLeaf(cur)) temp.push_back(cur->value);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for (int i = temp.size()-1; i >= 0;--i)
        res.push_back(temp[i]);
}

void addLeaf(Node *root, vector<int> &res){
    if (isLeaf(root)){
        res.push_back(root->value);
        return;
    }
    if (root->left) addLeaf(root->left,res);
    if (root->right) addLeaf(root->right,res);
}


vector<int> solve(Node *root){
   vector<int> res;
    if (!root) return res;
    if (!isLeaf(root)) res.push_back(root->value);
    addLeftBounary(root, res);
    addLeaf(root, res);
    addRightBounary(root , res);
   return res;
} 

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    // Call the solve function for boundary traversal
    vector<int> result = solve(root);

    // Print the result
    cout << "Boundary Traversal of the Binary Tree:" << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up dynamically allocated memory
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right->right;
    delete root->right->right->left;
    delete root->right->left->right;
    delete root->right->left->left;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
