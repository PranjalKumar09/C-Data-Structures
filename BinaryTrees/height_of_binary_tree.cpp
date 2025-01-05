#include <bits/stdc++.h>
using namespace std;

/*
Height of Binary Tree 
=====================
Maximum Depth


    Method 1 : Using Queue 
    Method 2 : Using recursion post order method


TC: O(N)
SC: O(N)

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

int solve1(Node *root){
    int depth = 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
   //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


      Node * temp = q.front();
        q.pop();
        if (!temp) depth++;

        // if temp is not null then 
        if (temp ){
            if (temp -> left ) q.push(temp->left);
            if (temp -> right ) q.push(temp->right);
        }
        else if (!q.empty())q.push(NULL);
        }
    return depth;
    }

int solve2(Node *root){
    if (!root) return 0;
    int lh = solve2(root->left);
    int rh = solve2(root->right);
    return 1+max(lh,rh);
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

    // Method 1: Using Queue
    int height1 = solve1(root);
    cout << "Height of the tree using queue: " << height1 << endl;

    // Method 2: Using Recursion (post-order method)
    int height2 = solve2(root);
    cout << "Height of the tree using recursion: " << height2 << endl;

    return 0;
}
