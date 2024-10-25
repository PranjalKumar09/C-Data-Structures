#include <bits/stdc++.h>
using namespace std;

/*
Replace every element with least greater element on its right
=============================================================
Input : [8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28]
Output: [18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1]    

Method 1: By BST
    TC: O(N^2)
    SC: O(H)

Method 2: By next greater method is efficent by stack 
    TC: O(N log N)
    SC: O(N)
*/

class Node {
public:
    int value;
    Node* left, *right;
    Node(int value) {
        this->value = value;
        this->left = this->right = NULL;
    }
};

Node* insert(Node* root, int val, int& suc){
    if(!root)    return new Node(val);
    
    if(val < root->value){
        suc = root->value;
        root->left = insert(root->left, val, suc);
    }
    else     root->right = insert(root->right, val, suc);
    return root;
}

vector<int> solve(vector<int> &arr){
    Node* root = NULL;
    for (int i = arr.size()-1; i > -1 ; i--){  
        int suc = -1;
        root = insert(root, arr[i], suc);
        arr[i] = suc;
    }
    return arr;
}



int main() {
    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    vector<int> result = solve(arr);

    cout << "Output: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}