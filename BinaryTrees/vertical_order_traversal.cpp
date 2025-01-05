#include <bits/stdc++.h>
using namespace std;

/*
Vertical Order Traversal
========================

map < vertical , map < level , multiset <int> >> 

x-> vertical , y-> horizontal



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


vector<vector<int>>  solve(Node *&root){
   map<int , map<int , multiset<int> > > nodes;
   queue<pair<Node *,pair<int, int> > > todo;
   todo.push({root,{0, 0}});

   while(!todo.empty()){
        auto p = todo.front();
        todo.pop();   
        Node *temp = p.first;
        int x = p.second.first ,  y = p.second.second;
        nodes[x][y].insert(temp->value);
        if (temp->left) todo.push({temp->left, {x-1, y+1}});
        if (temp->right)         todo.push({temp->right, {x+1, y+1}});
   }

vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main() {
    // Create a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);

    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    // leaf nodes
    
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    // Call the solve function for vertical order traversal
    vector<vector<int>> result = solve(root);

    // Print the result
    cout << "Vertical Order Traversal of the Binary Tree:" << endl;
    for (const auto &col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up dynamically allocated memory
    // Add your cleanup code here

    return 0;
}
