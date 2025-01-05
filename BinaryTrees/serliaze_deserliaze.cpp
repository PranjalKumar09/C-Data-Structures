#include <bits/stdc++.h>
using namespace std;

/* 
Serialize & Deserialize by B.T.
===============================

    B.T. -> Serialize -> String -> Deserialize
        can be done using any traversal
        
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
string serialize(Node *root) {
    if (!root) return "";
    string s = "";
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if (!temp) {
            s.append("#,");
        } else {
            s.append(to_string(temp->value));
            s.append(",");
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return s;
}

Node* deserialize(string s) {
    if (s.empty()) return NULL;
    stringstream ss(s); // allows string to
    string str;        // iterative over object
    getline(ss, str, ',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if (getline(ss, str, ',')) {
            if (str == "#") {
                temp->left = NULL;
            } else {
                temp->left = new Node(stoi(str));
                q.push(temp->left);
            }
        }
        if (getline(ss, str, ',')) {
            if (str == "#") {
                temp->right = NULL;
            } else {
                temp->right = new Node(stoi(str));
                q.push(temp->right);
            }
        }
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

int main() {
    // Constructing a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Serialize the tree
    string serializedTree = serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    // Deserialize the string back to a tree
    Node* deserializedRoot = deserialize(serializedTree);

    // Print inorder traversal of the deserialized tree to verify correctness
    cout << "Inorder Traversal of Deserialized Tree: ";
    inorderTraversal(deserializedRoot);
    cout << endl;

    return 0;
}