#include <bits/stdc++.h>
using namespace std;

/* 
K Sum Path
==========
    no of path which sum equal to K. It may start from any node & end at any node in downward direction.


    SC => O(N)
    TC => O(N)
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

void solve_util(Node *root, int& k , int& count , vector<int> &path){
    if (root == NULL) return;
    path.push_back(root->value);
    solve_util(root->left, k , count , path);
    solve_util(root->right, k , count , path);
    int sum = 0;
    for (int i = path.size()-1; i >= 0; i--) {// K-Sum Paths Ending at Current Node:
        sum += path[i];
        if (sum == k) count++;
    }
    path.pop_back();
}


int solve(Node* root, int k ){
    vector<int> path;
    int count = 0;
    solve_util(root, k , count, path);
    return count;
}
int main() {
    // Creating a sample binary tree:
    //        1
    //       / \
    //      3   -1
    //     / \   / \
    //    2   1 4   5
    //       / \    /
    //      1   2  6
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(2);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->left = new Node(6);

    int k = 5;
    int result = solve(root, k);
    std::cout << "Number of K-sum paths: " << result << std::endl;

    // Clean up memory (delete nodes)
    delete root->right->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}