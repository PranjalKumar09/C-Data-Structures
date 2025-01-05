#include <bits/stdc++.h>
using namespace std;

/*
Zig-Zag  or  Spiral Trivsal 
========     ==============

    -------------->
                    |
                    |
                    |
    <----------------

TC = O(N)
SC = O(N)
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

void print(vector<vector<int>>  &arr){  
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    cout << endl;
}


vector<vector<int>> solve(Node* arr){
    vector<vector<int>> ans;
    if (!arr) return ans;
    queue<Node*> q;
    q.push(arr);
    bool left_to_right = 1;
    while(!q.empty()){
        int n = q.size();
        vector<int> temp(n);
        
        for (int i = 0; i < n; i++){
            Node* curr = q.front();
            q.pop();
            int index = left_to_right ? i : n-1-i;
            temp[index] = curr->value;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            
        }
        left_to_right =!left_to_right;
        ans.push_back(temp);
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

    cout << "Zig-zag (spiral) order traversal of the tree:" << endl;
    vector<vector<int>> zigzag = solve(root);
    print(zigzag);

    // Clean up dynamically allocated memory
    delete root->right->right;  // original left->left
    delete root->right->left;   // original left->right
    delete root->right;         // original left
    delete root->left->right;   // original right->right
    delete root->left->left;    // original right->left
    delete root->left;          // original right
    delete root;

    return 0;
}
