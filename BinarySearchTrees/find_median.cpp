#include <bits/stdc++.h>
using namespace std;

/*
Find Median 
===========
Find median of BST in optmized SC
    
    by moris Inorder Traversal
    count no of nodes

    TC: O(N)
    SC: O(1)

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

void inorderTraversal(Node* root, vector<int>& inorder) {
    if (root == NULL) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->value);
    inorderTraversal(root->right, inorder);
}


int count_nodes(Node *root) {
    Node *curr = root;
    int count = 0;
    while (curr) {
        if (!curr->left) { // if left not exist
            count++;
            curr = curr->right;
        } else {
            Node *prev = curr->left;
            while (prev->right && prev->right!= curr) 
                prev = prev->right;  //  go to right most part of left
            
            if (!prev->right) { // now we reachec right most part now cunnect it to current  
            // then make current to left side
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

int solve(Node *root){
    
    if (!root) return 0;
    int count = count_nodes(root);
    int currCount = 0;
    Node* curr = root;
    Node* prev = NULL;

    while (curr) {
        if (!curr->left) {
            currCount++;
            if (count % 2 && currCount == (count + 1) / 2)
                return curr->value;
            else if (count % 2 == 0 && currCount == count / 2)
                prev = curr;
            else if (count % 2 == 0 && currCount == count / 2 + 1)
                return (prev->value + curr->value) / 2;
            curr = curr->right;
        } 
        
        else {
            Node* pre = curr->left;
            while (pre->right && pre->right != curr)
                pre = pre->right;
            if (!pre->right) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                currCount++;
                if (count % 2 != 0 && currCount == (count + 1) / 2)
                    return curr->value;
                else if (count % 2 == 0 && currCount == count / 2)
                    prev = curr;
                else if (count % 2 == 0 && currCount == count / 2 + 1)
                    return (prev->value + curr->value) / 2;
                prev = curr;
                curr = curr->right;
            }
        }
    }
    return 0;
}


int main() {
    // Constructing the binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(1);
    root->right = new Node(15);
    root->left->right = new Node(8);
    root->right->right = new Node(7);
    
    int median = solve(root);
    cout << "Median of the BST is: " << median << endl;
 

    // Clean up the dynamically allocated memory for the tree
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
