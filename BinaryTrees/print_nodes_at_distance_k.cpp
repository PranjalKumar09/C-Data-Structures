#include <bits/stdc++.h>
using namespace std;

/* 
Print all nodes at distance K
=============================

    Parent Mapping
    BFS while moving count distance

    visited hash
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
void Create_Parent_Mapping(Node* root, unordered_map<Node*, Node*> &parent_track){ //STEP 1 AND STEP 2
    parent_track[root]=NULL;
    queue<Node*> q; // by level order traversal
    q.push(root);
    while (!q.empty()){
        Node* current = q.front();
        q.pop();
        if (current->left){
            parent_track[current->left]=current;
            q.push(current->left);
        }
        if (current->right){
            parent_track[current->right]=current;
            q.push(current->right);
        }
    }
}

vector<int> solve(Node* root , Node * target , int k ){
    unordered_map<Node*, Node*> parent_track;
    Create_Parent_Mapping(root,parent_track);
    unordered_map<Node *, bool> visted;
    queue<Node*> q;
    q.push(target);
    visted[target]=1;
    int cur_level = 0;

    while(!q.empty()){
        int size  = q.size();
        if (cur_level++ == k) break;
        for(int i = 0 ; i < size ; i++){
            Node*current = q.front();
            q.pop();
            if (current->left && !visted[current->left]){
                q.push(current->left);
                visted[current->left] = 1;
            }
            if (current->right && !visted[current->right]){
                q.push(current->right);
                visted[current->right] = 1;
            }
            if (parent_track[current] && !visted[parent_track[current]]){
                q.push(parent_track[current]);
                visted[parent_track[current]] = 1;
            }
        }
    }
    vector <int> ans;
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        ans.push_back(current->value);
    }
    return ans;
}



int main() {
    // Creating a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    //   /         \
    //  7           8
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->right->right->right = new Node(8);

    // Define the target node and distance k
    Node* target = root->left; // target node with value 2
    int k = 2;

    // Find all nodes at distance k from the target node
    vector<int> result = solve(root, target, k);

    // Print the result
    cout << "Nodes at distance " << k << " from node " << target->value << " are: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}



