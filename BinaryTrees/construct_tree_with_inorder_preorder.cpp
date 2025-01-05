#include <bits/stdc++.h>
using namespace std;

/* 
Construct Tree with Inorder & Preorder
======================================
    [LNR] Inorder : 40 - 20 - 50 - 10 - 60 - 30
                   |      L      |  N  |   R   |

    [NLR] Preorder: 10 - 20 - 40 - 50 - 30 - 60
                     N
   
        10
       /   \
      20    30
     / \    /
    40  50 60       
                                (elem-1)  (elem+1)
    Inorder : Instart -> | Left    |    Elem | <- InEnd    
                          <nelem>
    nElem = elem - inStart
    elem is index


    Preorder: Prestart <-|  |                   |                           | <- PreEnd
                        (Prestart + 1)    (Prestart + nelem+1)          

    
         | prestart | preEnd | Instart | InEnd |
    ================|========|=========|=======|====    
    Left | prestart |prestart| Instart | elem-1|
         |   + 1    |+nlem   |         |       |
    -----|----------|--------|---------|-------|----
    Right| prestart | preend |  elem+1 | inEnd |
         |+nelem + 1|        |         |       |


    TC : O(N)
    SC : O(N)
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

Node* solve_util(vector<int> &preorder , int preStart, int preEnd, vector<int> &inorder , int inStart, int inEnd , map<int , int> & mp){
    if (preStart > preEnd || inStart > inEnd) return NULL;
    Node *root = new Node(preorder[preStart]);
    int elem = mp[root->value]; // elem is index
    int nElem = elem - inStart; 
    root->left = solve_util(preorder , preStart+1, preStart+nElem , inorder , inStart, elem-1 , mp);
    root->right = solve_util(preorder , preStart+nElem+1, preEnd, inorder , elem+1 , inEnd,mp);
    return root;
}


Node* solve(vector<int>& inorder , vector<int>& preorder){
    int preStart = 0 , preEnd = preorder.size()-1;
    int inStart = 0 , inEnd = inorder.size()-1;
    map <int , int> mp;
    for (int i = 0 ; i < inorder.size() ; i++)
        mp[inorder[i]] = i;
    return solve_util(preorder ,preStart , preEnd, inorder , inStart , inEnd , mp);

}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}

int main() {
    // Sample inorder and preorder traversals
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};

    // Construct the binary tree
    Node* root = solve(inorder, preorder);

    // Print the inorder traversal of the constructed tree
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    // Clean up memory (delete nodes)
    // Implement a function to delete all nodes if needed

    return 0;
}