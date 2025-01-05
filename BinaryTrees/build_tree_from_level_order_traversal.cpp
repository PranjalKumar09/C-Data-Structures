#include <bits/stdc++.h>
using namespace std;

/*               _________________________
Build Tree from  | level order traversal | -> Queue
==========================================

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


void solve(Node *&root){
    queue<Node*> q;
    cout << "Enter data for root "<< endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()) {
        Node * temp = q.front();
        q.pop();
        cout << "Enter left node for "<< temp->value << endl;
        int left_data;
        cin >> left_data;
        if (left_data != -1){
            temp->left = new Node(left_data);
            q.push(temp->left);
        }
        cout << "Enter right node for " << temp->value << endl;
        int right_data;
        cin >> right_data;
        if (right_data != -1){
            temp->right = new Node(right_data);
            q.push(temp->right);
        } }
}
int main() {
    Node *root = NULL;
    solve(root);

    return 0;
}