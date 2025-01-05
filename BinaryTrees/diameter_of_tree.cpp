    #include <bits/stdc++.h>
    using namespace std;

    /* 
    Diameter of Tree
    ================

    longest path may or not pass through root between 2 nodes

        Method 1: Using hight method & diameter recursion
            TC :  O(N^2)

        Method 2: Using both recursion in 1 function 
            TC :  O(N)
            SC :  O(1) + O(H) (Recursion Stack)


    */


    class  node {
    public:
        int data;
        node *left, *right;

        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

        node* BuildTree(){
            cout << "Enter the Data (-1 for no node): ";
            int data;
            cin >> data;
            if (data == -1) return NULL;

            node *root = new node(data);
            cout << "Enter data in left of " << data << ": ";
            root->left = BuildTree();
            cout << "Enter data in right of " << data << ": ";
            root->right = BuildTree();
            return root;
        }
    };




    int height(node *root){
        if (!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1+max(lh,rh);
    } 

    int diameter(node* root){
        if (!root) return 0;

        int lh = diameter(root->left);
        int rh = diameter(root->right);
        int op3 = height(root->left)+height(root->right)+1;
        return max(lh, max(rh , op3));
    }

    int diameter2Util(node* root, int& count) {
        if (!root) return 0;

        int lh = diameter2Util(root->left, count);
        int rh = diameter2Util(root->right, count);

        count = max(count, lh + rh + 1);

        return 1 + max(lh, rh);
    }

    int diameter2(node* root) {
        int count = 0;
        diameter2Util(root, count);
        return count;
    }

    int main() {
        // Constructing the binary tree
        node* root = new node(1);
        root->left = new node(2);
        root->right = new node(3);
        root->left->left = new node(4);
        root->left->right = new node(5);
        root->right->left = new node(6);
        root->right->right = new node(7);

        // Calculating the diameter using the first method
        int dia1 = diameter(root);
        cout << "Diameter of the tree (Method 1): " << dia1 << endl;

        // Calculating the diameter using the second method
        int dia2 = diameter2(root);
        cout << "Diameter of the tree (Method 2): " << dia2 << endl;

        // Cleaning up memory (optional in competitive programming, but good practice)
        delete root->left->left;
        delete root->left->right;
        delete root->right->left;
        delete root->right->right;
        delete root->left;
        delete root->right;
        delete root;

        return 0;
    }
