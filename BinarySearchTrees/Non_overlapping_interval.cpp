#include <bits/stdc++.h>
using namespace std;

/*
Non-Overlapping Interval
========================
i/p : { {1,5}, {3,7}, {2,6}, {10,15} {5,6}, {4,100}}

Method 1: Brute Force
    TC: O(N^2)
    SC: O(N)

Method 2: By BST
    TC: O(N log N)
    SC: O(N)
*/

class Node {
public:
    int value;
    Node* left, *right;
    Node(int value) {
        this->value = value;
        this->left = this->right = NULL;
    }
};
struct Interval {
    int low, high;
    Interval(int l, int h) : low(l), high(h) {}
};

bool doOverlap(const Interval& a, const Interval& b) {// a subset of b
    return (a.low <= b.high && b.low <= a.high);
}

Interval* solve(Node* root, const Interval& i) {
    if (!root) return nullptr;
    
    if (i.low < root->value) {
        Interval* leftResult = solve(root->left, i);
        if (leftResult) return leftResult;
    } 
    if (i.high > root->value) {
        Interval* rightResult = solve(root->right, i);
        if (rightResult) return rightResult;
    }

    if (!doOverlap(Interval(root->value, root->value), i))
        return new Interval(root->value, root->value);

    return nullptr;
}

int main() {
    // Example usage
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    Interval i(6, 11);
    Interval* result = solve(root, i);
    
    if (result)
        cout << "Non-overlapping interval found: [" << result->low << ", " << result->high << "]" << endl;
    else
        cout << "No non-overlapping interval found." << endl;
    
    return 0;
}
