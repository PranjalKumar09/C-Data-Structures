#include <bits/stdc++.h>
using namespace std;

/* 
Is BST a Heap?
==============

    Method 1 : By checking BT a CBT then further
        TC : O(N)
        SC : O(log N) 

    Method 2 : Optmized Solution
        Check if child greater than parent 

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


int count_nodes(Node *root){
    if (!root) return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}
bool isComplete(Node *root,int index , int number_nodes){
    // tree should complete otherwise its index will more than total number of nodes
    if (!root) return true;
    if (index >= number_nodes) return false;
    return isComplete(root->left, 2*index + 1, number_nodes) && isComplete(root->right, 2*index + 2, number_nodes);
}
bool isHeap(Node *root){
    if (!root->left && !root->right) return 1;
    if (!root->right) return root->value  >= root->left->value ;
    if (root->value >= root->left->value && root->value >= root->right->value)
        return isHeap(root->left) && isHeap(root->right);
    return false;
}
bool solve1(Node* root){
    return isComplete(root, 0, count_nodes(root)) && isHeap(root);
}


bool solve2(Node* root){
    bool result = 1;
    
    // check if child greater than parent 
    if (root && (((root->left && root->left->value > root->value)) || (root->right && root->right->value > root-> value))) return 0; 
     
    // check if left subtree has child but right null
    if (root->left && ((root->left->left || root->left->right)) && !root->right) return 0;

    // check if right subtree has child but left null
    if (root->right && ((root->right->left || root->right->right)) && !root->left) return 0;

    // recursive call
    if (root && root->right) result = result && solve2(root->right);

    if (root && root->left) result = result && solve2(root->left);

    return result;
}


int main()
{
    Node* root = NULL;
    root = new Node(10);
    root->left = new Node(91);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);
    root->left->right->left = new Node(1);
 
    // Function call
    if (solve1(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
 
    // Function call
    if (solve2(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
 
    return 0;
}
 
// Th

