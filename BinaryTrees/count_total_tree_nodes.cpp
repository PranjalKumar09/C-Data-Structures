#include <bits/stdc++.h>
using namespace std;

/* 
Count complete total Tree Nodes
===============================

    Method 1: Traversing with count++
        TC : O(N)
        SC : O(H)
        wrost SC : O(log(N)) hight in complete tree
    
    Method 2: Using Algo
        TC : O(log(N))^2
        SC : O(N) -> at wrost case when rh!=lh
        
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

int find_Height_Left(Node *root){
    int height = 0;
    while(root){
        height++;
        root = root->left;
    }
    return height;
}
int find_Height_Right(Node *root){
    int height = 0;
    while(root){
        height++;
        root = root->right;
    }
    return height;
}


int solve(Node *root){
    if (!root) return 0;
    int lh = find_Height_Left(root->left);
    int rh = find_Height_Right(root->right);
    if (lh == rh) return (1<<(lh+1))-1;
    return 1+solve(root->left)+solve(root->right);
}




int main() {
    // Constructing a sample complete binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    // Calculating the total number of nodes
    int totalNodes = solve(root);

    // Printing the total number of nodes
    cout << "The total number of nodes in the complete binary tree is: " << totalNodes << endl;

    return 0;
}
