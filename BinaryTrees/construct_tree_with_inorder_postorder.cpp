#include <bits/stdc++.h>
using namespace std;

/* 
Construct Tree with Inorder & Postorder
=======================================
    [LNR] Inorder : 40 - 20 - 50 - 10 - 60 - 30   <map>
                   |      L      |  N  |   R   |

    [NLR] Postorder: 40 - 50 - 20 - 60 - 30 - 10
                                               N



                                        
   
        10
       /   \
      20    30
     / \    /
    40  50 60       
    

                 (Instart)   (elem-1)      (elem+1)
    Inorder  :    |  Left     |  elem           | right |    
    Postorder:    |  Left     |      right        |     | <- postend
                (poststart)  (postst+nelem) (postend-1)   


    
         |poststart | postEnd | Instart | InEnd |
    ================|=========|=========|=======|====    
    Left |poststart |poststart| Instart | elem-1|
         |   + 1    |+nlem    |         |       |
    -----|----------|---------|---------|-------|----
    Right|poststart |postend  |  elem+1 | inEnd |
         |+nelem + 1|    -1   |         |       |

    in this node is postend 

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

Node* solve_util(vector<int> &postorder , int postStart, int postEnd, vector<int> &inorder , int inStart, int inEnd , map<int , int> & mp){
    if (postStart > postEnd || inStart > inEnd) return NULL;
    Node *root = new Node(postorder[postEnd]);
    int elem = mp[root->value]; // elem is index
    int nElem = elem - inStart; 
    root->left = solve_util(postorder , postStart, postStart+nElem-1, inorder , inStart, elem-1 , mp);
    root->right = solve_util(postorder , postStart+nElem, postEnd-1, inorder , elem+1 , inEnd,mp);
    return root;
}


Node* solve(vector<int>& inorder , vector<int>& postorder){
    int postStart = 0 , postEnd = postorder.size()-1;
    int inStart = 0 , inEnd = inorder.size()-1;
    map <int , int> mp;
    for (int i = 0 ; i < inorder.size() ; i++)
        mp[inorder[i]] = i;
    return solve_util(postorder ,postStart , postEnd, inorder , inStart , inEnd , mp);

}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}

int main() {
    // Sample inorder and postorder traversals
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> postorder = {4,5,2,6,3,1};

    // Construct the binary tree
    Node* root = solve(inorder, postorder);

    // Print the inorder traversal of the constructed tree
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    // Clean up memory (delete nodes)
    // Implement a function to delete all nodes if needed

    return 0;
}