#include <bits/stdc++.h>
using namespace std;

/*
Sum of Longest Bloodline
========================
(from root)

    Method 1 : Recursion Fn with multiple Arguments 
        TC: O(H)
        SC: O(H)

    Method 2 : Recursion Fn with 1 Arguments 



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


// Function to find the sum of the longest bloodline
void solve1(Node *root, int sum, int &maxSum, int len, int &maxLen) {
    if (!root) {
        if (len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum += root->value;
    solve1(root->left, sum, maxSum, len + 1, maxLen);
    solve1(root->right, sum, maxSum, len + 1, maxLen);
}

int findLongestBloodlineSum(Node *root) {
    int maxSum = INT_MIN;
    int maxLen = 0;
    solve1(root, 0, maxSum, 0, maxLen);
    return maxSum;
}

// Function to find the maximum path sum in the binary tree
int solve2(Node *root, int &maxi) {
    if (!root) return 0;
    int left = max(0, solve2(root->left, maxi));
    int right = max(0, solve2(root->right, maxi));
    int val = root->value;
    maxi = max(maxi, left + right + val);
    return max(left, right) + val;
}

int findMaxPathSum(Node *root) {
    int maxi = INT_MIN;
    solve2(root, maxi);
    return maxi;
}

int main() {
    // Create a binary tree
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    // Method 1: Finding sum of longest bloodline
    int longestBloodlineSum = findLongestBloodlineSum(root);
    cout << "Sum of Longest Bloodline: " << longestBloodlineSum << endl;

    // Method 2: Finding maximum path sum
    int maxPathSum = findMaxPathSum(root);
    cout << "Maximum Path Sum: " << maxPathSum << endl;

    return 0;
}