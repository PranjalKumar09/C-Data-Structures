#include <iostream>
using namespace std;

/* 
IMPLEMENTATION OF TREE

 */


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

int main() {
    node *root = new node(0); // Create an instance of the node class
    root = root->BuildTree(); // Call the BuildTree function on the node instance

    // Now, you can use the 'root' pointer to access the entire binary tree.
    return 0;
}
