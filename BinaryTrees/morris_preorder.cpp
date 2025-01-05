#include <bits/stdc++.h>
using namespace std;

/*
Morris Preorder Traversal 
========================


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


vector<int> solve(Node *root) {
    vector<int> arr;
    Node *curr = root;
    while (curr) {
        if (!curr->left) { // if left not exist
            arr.push_back(curr->value);
            curr = curr->right;
        } else {
            Node *prev = curr->left;
            while (prev->right && prev->right!= curr) 
                prev = prev->right;  //  go to right most part of left
            
            if (!prev->right) { // now we reachec right most part now cunnect it to current  
            // then make current to left side
                arr.push_back(curr->value);
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                // arr.push_back(curr->value);
                curr = curr->right;
            }
        }
    }
    return arr;
}

void print(vector<int> &solve){
    for (int i = 0; i < solve.size(); i++) 
        cout << solve[i] << " ";
    
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

    vector<int> traversal = solve(root);
    print(traversal); //  1 2 4 5 3 6 7 

    // Clean up dynamically allocated memory
    delete root->right->right;  // original left->left
    delete root->right->left;   // original left->right
    delete root->right;         // original left
    delete root->left->right;   // original right->right
    delete root->left->left;    // original right->left
    delete root->left;        // original right
    delete root;

    return 0;
}