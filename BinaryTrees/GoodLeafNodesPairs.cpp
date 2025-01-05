#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int count, distance;

    vector<int> solve(TreeNode *&root)
    {
        if (!root)
            return {};

        if (!root->left && !root->right)
            return {1};

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        for (int it1 : left)
            for (int it2 : right)
                if (it1 + it2 <= distance)
                    count++;

        vector<int> ans;

        for (int it1 : left)
            if (it1 + 1 <= distance)
                ans.push_back(it1 + 1);

        for (int it2 : right)
            if (it2 + 1 <= distance)
                ans.push_back(it2 + 1);

        return ans;
    }

    int countPairs(TreeNode *&root, int &distance)
    {
        count = 0;
        this->distance = distance;
        solve(root);
        return count;
    }
};

int main()
{
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int distance = 3;
    cout << "Number of pairs: " << solution.countPairs(root, distance) << endl;

    return 0;
}
