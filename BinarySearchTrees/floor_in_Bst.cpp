#include <bits/stdc++.h>
using namespace std;

/*
Floor in BST
===========
    Equal or just less than int input value
    TC -> O(log N)
    wrost -> O(1)
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
int solve(Node* root, int target) {
    int floor = -1;
    while (root) {
        if (root->value == target)
            return target;
        else if (root->value < target){
            floor = root->value;
            root = root->right;}
        else 
            root = root->left;
        
    }
    return floor;
}
int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int target = 7;

    int result = solve(root, target);
    cout << "Ceiling of " << target << " is: " << result << endl;

    return 0;
}
