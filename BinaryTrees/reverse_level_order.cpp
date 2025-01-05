#include <bits/stdc++.h>
using namespace std;

/* 
REVERSE LEVEL ORDER

    Method 1: Recursive Function
                TC : O(n^2)
                SC : O(n)

    Method 2: Queues & Stacks 
                TC : O(n)
                SC : O(n)

    Method 3: Hash Map
                TC : O(n)
                SC : O(n)

*/

// Node structure for the binary tree
class TreeNode {
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

// Function to perform reverse level order traversal
vector<int> reverseLevelOrder(TreeNode *root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    stack<int> s; // Stack to store the values in reverse order

    q.push(root);
    while (!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();

        // Push the value of the current node into the stack
        s.push(temp->val);

        // Enqueue the right child first to ensure left child is processed first when popped
        if (temp->right) q.push(temp->right);
        if (temp->left) q.push(temp->left);
    }

    // Pop values from the stack and store them in the result vector
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

int main() {
    // Example binary tree construction
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform reverse level order traversal
    vector<int> result = reverseLevelOrder(root);

    // Print the result
    cout << "Reverse Level Order Traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
