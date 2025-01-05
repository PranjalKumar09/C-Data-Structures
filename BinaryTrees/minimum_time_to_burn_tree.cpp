#include <bits/stdc++.h>
using namespace std;

/* 
Minimum time to Burn Tree 
=========================

    Each connected element burn at next second. Any node can burn, and be Target node

    Approach->
        1) Node to parent mapping map<Node *, Node *> node_to_parent
        (by level order traversal)

        2) Find target Node

        3) visited-> map <Node* , bool >, queue

    TC -> O(N)+O(N)  or O(NlogN) map dependent
    SC -> O(N)+O(N)



    This will give error if target not present in Tree y
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
Node* Create_Parent_Mapping(Node* root, int target, map<Node*, Node*> &nodeToParent){ //STEP 1 AND STEP 2
    nodeToParent[root]=NULL;
    Node *res = NULL;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        Node* front = q.front();
        q.pop();
        if (front->value == target)
            res = front;
        if (front->left){
            nodeToParent[front->left]=front;
            q.push(front->left);
        }
        if (front->right){
            nodeToParent[front->right]=front;
            q.push(front->right);
        }
    }
    return res;   
}

int burnTree(Node* root ,map<Node*, Node*> &nodeToParent ){
    map<Node* , bool >  visted ;
    queue<Node*> q;
    q.push(root);
    visted[root]=1;
    int ans = 0;

    while(!q.empty()){
        bool flag = 0;
        int size  = q.size();
        for(int i = 0 ; i < size ; i++){
            Node*front = q.front();
            q.pop();
            if (front->left && !visted[front->left]){
                q.push(front->left);
                visted[front->left] = 1;
                flag = 1;
            }
            if (front->right && !visted[front->right]){
                q.push(front->right);
                visted[front->right] = 1;
                flag = 1;
            }
            if (nodeToParent[front] && !visted[nodeToParent[front]]){
                q.push(nodeToParent[front]);
                visted[nodeToParent[front]] = 1;
                flag = 1;
            }
        }
        if (flag) ans++;
    }
    return ans;
}

int solve(Node* root , int target){
    map<Node*, Node*> NodeToParent;
    Node* targetNode = Create_Parent_Mapping(root, target , NodeToParent);
    return burnTree(targetNode , NodeToParent);
}

int main() {
    // Creating a sample binary tree:
    //         10
    //       /    \
    //      1      2
    //     / \    / \
    //    3   4  5   6     
    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    int result = solve(root , 3);
    cout << "Tree Burn in: " << result << endl; // 10 + (3 + 4) + (5 + 6) => 10 + 7 + 11 

    // Clean up memory (delete nodes)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}

