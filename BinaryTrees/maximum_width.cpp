#include <bits/stdc++.h>
using namespace std;

/*
Maximum Width 
=============
(no of nodes in level b/w any 2 nodes)

    Here values of nodes not matter 
    First Node & last node of last level

Imaginary Index
     1
    /  \ 
   /    \
  2      3  
 / \    / \ 
4   5  6   7

0 based Indexing
    current -> i
    left    -> 2*i + 1
    right   -> 2*i + 2

1 based Indexing
    current -> i
    left    -> 2*i
    right   -> 2*i + 1

do it as 
     0
    /  \ 
   /    \
  0      1  
 / \    / \ 
0   1  2   3
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

int solve(Node *root) {
    if (!root) return 0;
    int ans = 0 ;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int size = q.size();
        int mmin = q.front().second;
        int first , last ;
        for (int i = 0 ; i < size ; i++) {
            int cur_id = q.front().second - mmin ;
            Node* node = q.front().first ;
            q.pop();
            if (i == 0) first = cur_id ;
            if (i == size - 1) last = cur_id ;
            if (node->left) q.push({node->left, cur_id * 2 + 1});
            if (node->right) q.push({node->right, cur_id * 2 + 2});
            }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

void print(vector<int> &solve){
    for (int i = 0; i < solve.size(); i++) 
        cout << solve[i] << " ";
    
    cout << endl;
}
int main() {
    // Constructing the tree
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(9);

    // Calculating the maximum width
    int maxWidth = solve(root);

    // Printing the maximum width
    cout << "The maximum width of the binary tree is: " << maxWidth << endl;

    return 0;
}~~