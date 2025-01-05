#include <bits/stdc++.h>
using namespace std;

/*
Preorder, Inorder, Postorder in 1 Traversal
===========================================

Lifo    Stack(node,    num)
                    (count)

    if num == 1
        preorder
        push_by++
        left
    
    if num == 2
        inorder 
        ++
        right
    
    if num == 3
        postorder


TC: O(3N)
SC: O(4N)

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

vector<vector<int>> solve(Node *root){
    stack<pair<Node *, int> > st;
    vector<vector<int>> result(3);
    if (!root) return result;

    st.push({root, 1});
    vector<int> &pre = result[0];
    vector<int> &in = result[1];
    vector<int> &post = result[2];

    while(!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1){
            pre.push_back(it.first->value);
            it.second++;
            st.push(it);
            if (it.first->left)
                st.push({it.first->left,1});
        }
        else if (it.second == 2){
            in.push_back(it.first->value);
            it.second++;
            st.push(it);
            if (it.first->right)
                st.push({it.first->right,1});
        }
        else post.push_back(it.first->value);

    }
    
    return result;
}


void printTraversal(const vector<int> &traversal, const string &name) {
    cout << name << " Traversal: ";
    for (int val : traversal) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Create a simple tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Perform the traversal
    vector<vector<int>> result = solve(root);

    // Print the results
    printTraversal(result[0], "Preorder");
    printTraversal(result[1], "Inorder");
    printTraversal(result[2], "Postorder");

    return 0;
}
