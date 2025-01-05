#include <bits/stdc++.h>
using namespace std;

/* 
LEVEL ORDER TRAVERSAL
(print level by level)

TC = O(n)
SC = O(n)


    To print level no: declare 2nd array vector<vector<int>>

    Inside while loop, declare list to store node of level then set another for loop, which iterate for size of queue & node this for loop write same logic as previous code

    For loop insure that all nodes of particular level inserted that all nodes of particular level inserted together & when iteratoin of for loops ends , query contains element of only one level at a time (inner for loops runs for q.size())

    Inside for loop we push value of temp to level
    
    After this, push level to answer


->  TC will remain same


Application

    It is actually B.F.S.
    Finding connected components to graph D.S.

 */



void print(vector<int> ans){
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}




class node {
public:
    int data;
    node *left, *right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    node* BuildTree(){
        cout << "Enter the Data (-1 for no node): ";
        int data;
        cin >> data;
        if (data == -1) return NULL;

        node *root = new node(data);
        cout << "Enter data in left of " << data << ": ";
        root->left = BuildTree();
        cout << "Enter data in right of " << data << ": ";
        root->right = BuildTree();
        return root;
    }
};

vector<int> solve(node *root){
    vector<int> ans;
    queue<node*> q; // take queue data structure
    q.push(root);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        // 
        ans.push_back(temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return ans;
}


int main() {
    node *root = new node(0); // Create an instance of the node class
    root = root->BuildTree(); // Call the BuildTree function on the node instance

    vector<int> ans = solve(root);


    print(ans);


    return 0;
}
