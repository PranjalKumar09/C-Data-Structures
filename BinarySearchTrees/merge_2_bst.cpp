#include <bits/stdc++.h>
using namespace std;

/*
Merge 2 BST
===========

    Method 1:   
        i/p: BST 1,     BST 2
             inorder1,  inorder2
             Merge 2 sorted array
             Convert to BST (Inorder to BST)
        TC: O(N1 + N2)
        TC: O(N1 + N2)

    Method 2: Doing in Sane memory by BT as LL

        Convert BST to LL , TC: O(N1 + N2)
        Merge 2 sorted LL
        Sorted LL to BST(balanced)


         

*/

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(NULL), right(NULL) {}
};
// solve1
void inorder(Node* root, vector<int>& inorderVal) {
    if (!root) return;
    inorder(root->left, inorderVal);
    inorderVal.push_back(root->value);
    inorder(root->right, inorderVal);
}

// solve 1
vector<int> mergeArray(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size()) {
        merged.push_back(arr1[i++]);
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j++]);
    }
    return merged;
}
// solve 1
Node* inorderToBST(int start, int end, const vector<int>& inorderVal) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = new Node(inorderVal[mid]);
    root->left = inorderToBST(start, mid - 1, inorderVal);
    root->right = inorderToBST(mid + 1, end, inorderVal);
    return root;
}


// Helper function to convert BST to sorted linked list
void bstToSortedLL(Node* root, Node*& head) {
    if (!root) return;
    bstToSortedLL(root->right, head);
    root->right = head;
    head = root;
    bstToSortedLL(root->left, head);
}

// Helper function to merge two sorted linked lists
Node* mergeSortedLL(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;
    while (l1 && l2) {
        if (l1->value < l2->value) {
            tail->right = l1;
            l1 = l1->right;
        } else {
            tail->right = l2;
            l2 = l2->right;
        }
        tail = tail->right;
    }
    tail->right = l1 ? l1 : l2;
    return dummy.right;
}

// Helper function to count the number of nodes in a linked list
int countNodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->right;
    }
    return count;
}

// Helper function to convert sorted linked list to balanced BST
Node* sortedLLToBST(Node*& head, int n) {
    if (n <= 0) return NULL;
    Node* left = sortedLLToBST(head, n / 2);
    Node* root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}

Node* solve(Node* root1, Node* root2) {
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);
    vector<int> merged = mergeArray(bst1, bst2);
    return inorderToBST(0, merged.size() - 1, merged);
}

// Function to merge two BSTs into a balanced BST
Node* solve2(Node* root1, Node* root2) {
    Node* head1 = NULL;
    Node* head2 = NULL;
    
    // Convert both BSTs to sorted linked lists
    bstToSortedLL(root1, head1);
    bstToSortedLL(root2, head2);

    // Merge the two sorted linked lists
    Node* mergedHead = mergeSortedLL(head1, head2);

    // Convert the merged sorted linked list to a balanced BST
    int totalNodes = countNodes(mergedHead);
    return sortedLLToBST(mergedHead, totalNodes);
}

// Helper function to print the BST in inorder traversal
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}

// Helper function to print the BST in preorder traversal
void printPreorder(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Constructing two sample BSTs:
    // BST 1:
    //         3
    //        / \
    //       1   5
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    // BST 2:
    //         4
    //        / \
    //       2   6
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    // Merge the two BSTs into a balanced BST
    Node* mergedRoot = solve2(root1, root2);

    // Print the merged BST to verify it's constructed correctly
    cout << "Inorder Traversal of the Merged BST: ";
    printInorder(mergedRoot);
    cout << endl;

    cout << "Preorder Traversal of the Merged BST: ";
    printPreorder(mergedRoot);
    cout << endl;

    // Clean up the dynamically allocated memory for the original trees
    delete root1->right;
    delete root1->left;
    delete root1;
    delete root2->right;
    delete root2->left;
    delete root2;

    // Clean up the dynamically allocated memory for the merged tree
    // A utility function to delete the tree nodes can be added if needed
    return 0;
}





