#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool search_it(int &target, TreeNode* &root, string &str){
        if (root->val==target) return 1;
        if (root->left && search_it(target, root->left, str)) str.push_back('L');
        else if  (root->right && search_it(target, root->right, str)) str.push_back('R');
        return !str.empty();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path1, path2;
        search_it(startValue, root, path1);
        search_it(destValue, root, path2);
        while(!path1.empty() && !path2.empty() && path1.back() == path2.back()){
            path1.pop_back();
            path2.pop_back();
        }
        reverse(path2.begin(), path2.end());
        return string(path1.size(), 'U') + path2;
    }
};

// Helper function to build a binary tree from a vector
TreeNode* buildTree(const vector<int>& nodes, int idx = 0) {
    if (idx >= nodes.size() || nodes[idx] == -1) return nullptr;
    TreeNode* root = new TreeNode(nodes[idx]);
    root->left = buildTree(nodes, 2 * idx + 1);
    root->right = buildTree(nodes, 2 * idx + 2);
    return root;
}

int main() {
    Solution sol;

    // Example binary tree: [5, 1, 2, 3, -1, 6, 4]
    vector<int> nodes = {5, 1, 2, 3, -1, 6, 4};
    TreeNode* root = buildTree(nodes);

    int startValue = 3;
    int destValue = 6;
    string result = sol.getDirections(root, startValue, destValue);
    cout << "Directions from " << startValue << " to " << destValue << ": " << result << endl;

    return 0;
}
