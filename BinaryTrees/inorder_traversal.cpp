 #include <bits/stdc++.h>
using namespace std;

/* 
INORDER TRAVERSAL (LNR)

    Method 1 : By recursion
    Method 2 : By stack


Applications

    Inorder of B.S.T. , we get in increasing order
    We can get reversed order/ decreasing
    Order by doing this in reversal order

*/

class TreeNode {
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};


void inorderTraversal(TreeNode *curr, vector<int> &inorder){
    if (!curr) return;
    inorderTraversal(curr->left, inorder);
    inorder.push_back(curr->val);
    inorderTraversal(curr->right, inorder);
}

void inorderTraversal2(TreeNode *curr, vector<int> &inorder){
    stack <TreeNode *> s;
    while(1){
        if (curr){
            s.push(curr);
            curr = curr->left;
        }
        else {
            if (s.empty()) break;
            curr = s.top();
            s.pop();
            inorder.push_back(curr->val);
            curr = curr->right;
        }
    }
}

void print(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}




int main() {
    // Example binary tree construction
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result;
    inorderTraversal(root,result);
    print(result);

    result.clear();

    inorderTraversal2(root,result);
    print(result);

    return 0;
}
