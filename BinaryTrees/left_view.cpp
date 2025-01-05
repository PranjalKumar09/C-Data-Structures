#include <bits/stdc++.h>
using namespace std;

/* 
Left View
==========


    solve_util(root->left, level+1 , ans);
    solve_util(root->right, level+1, ans);


*/

// Node structure for the binary tree
class Node {
public:
    int val;
    Node *left, *right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};



void solve_util(Node *root, int level, vector<int> &ans){
    if (!root) return;
    if (ans.size()==level) ans.push_back(root->val); // only happens first time
    solve_util(root->left, level+1 , ans);
    solve_util(root->right, level+1, ans);
    }


vector<int> solve(Node *root){
    vector<int> ans;
    solve_util(root, 0,ans);
    return ans;
}


void print_array(vector<int> &array){
    for (int i=0; i<array.size(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    /*
             1
            / \
           2   3
            \
             4
              \
               5
                \
                 6
    */

    // Call the solve function for top view
    vector<int> result = solve(root);

    // Print
    cout << "Left View of the Binary Tree:" << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;






    return 0;
}
