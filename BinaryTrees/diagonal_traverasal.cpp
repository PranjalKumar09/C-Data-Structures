#include <bits/stdc++.h>
using namespace std;

/* 
Digonal Traversal
=================

         1
        / \
       2   3
        \
         4
          \
           5
            \
             6

    level 0-> 1 - 3
    level 1-> 2 - 4 - 5 - 6





*/

class Node {
public:
    int val;
    Node *left, *right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

void fn(Node *root, int d , map <int, vector <int> > &DP){
    if (!root) return;
    DP[d].push_back(root->val);
    fn(root->left, d+1, DP);
    fn(root->right, d, DP);
}



void solve(Node *root){
    map <int, vector<int>> DP;
    fn(root, 0, DP);
    cout << "Diagonal Traversal of Binary Tree" << endl;
    for (auto it : DP) {
        vector <int> v = it.second;
        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }

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

   solve(root);





    return 0;
}
