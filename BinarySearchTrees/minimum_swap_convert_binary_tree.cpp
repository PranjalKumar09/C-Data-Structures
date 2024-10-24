#include <bits/stdc++.h>
using namespace std;

/*
Minimum swap to convert Binary Tree to BST
==========================================
    B.T.    -> Inorder
    Inorder -> Q) Minimum Swaps to make array sorted
    Array   -> (sorted inorder) -> construct tree
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


void inorderTraversal(Node* root, vector<int>& inorder){
    if (!root) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->value);
    inorderTraversal(root->right, inorder);
}

int solve(Node* root){
    vector<int> inorder;
    inorderTraversal(root, inorder);
    
    vector<int> temp = inorder;
    sort(temp.begin(), temp.end());
    int count = 0;
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++) 
        mp[inorder[i]] = i;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i]!= temp[i]) {
            count++;
            
            int misplaced = inorder[i];
            int correctIndex = mp[temp[i]];

            inorder[i] = temp[i];
            inorder[correctIndex] = misplaced;

            // Update the indices in the map
            mp[misplaced] = correctIndex;
            mp[temp[i]] = i;
            }

    }
    return count;

}


int main() {
    // Example usage
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right->right = new Node(9);

    int swaps = solve(root);
    
    cout << "Minimum swaps to convert the binary tree to a BST: " << swaps << endl;
    
    return 0;
}
