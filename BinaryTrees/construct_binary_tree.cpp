#include <bits/stdc++.h>
using namespace std;

/*
Construct Binary Tree from String with Bracket Representation
=============================================================

    i/p: 4(2(3)(1))(6(5))
          <--Left--><Right>

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

Node* solve(const string &s, int &start) {
    if (start >= s.size()) return NULL;
    cout << "checking " << s << " start " << start << endl;
    int num = 0;
    bool hasNumber = false;
    
    // Extract number
    while (start < s.size() && isdigit(s[start])) {
        num = num * 10 + (int)(s[start] - '0');
        start++;
        hasNumber = true;
    }

    if (!hasNumber) return NULL; // No valid number found
    
    Node* root = new Node(num);
    
    // Check for left child
    if (start < s.size() && s[start] == '(') {
        start++; // Skip '('
        root->left = solve(s, start);
        if (start < s.size() && s[start] == ')') start++; // Skip ')'
    }

    // Check for right child
    if (start < s.size() && s[start] == '(') {
        start++; // Skip '('
        root->right = solve(s, start);
        if (start < s.size() && s[start] == ')') start++; // Skip ')'
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

int main() {
    string treeStr;
    cout << "Enter the string representation of the tree: "; // Example: 4(2(3)(1))(6(5))
    cin >> treeStr;
    cout << "length " << treeStr.length() << endl;
    int start = 0;
    Node* root = solve(treeStr, start);
    cout << "Inorder traversal of the constructed tree: ";
    inorder(root);
    cout << endl;

    return 0;
}