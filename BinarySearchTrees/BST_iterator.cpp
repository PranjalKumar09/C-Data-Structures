#include <bits/stdc++.h>
using namespace std;

/*
Making BST Iterator
===================

  7
 /  \
3    15
    /  \
   9   20

Inorder     3 7 9 15 20
           ^
next       |  ---->
       intiliazed
hasNext  if next => true
         else False

next = 7 , hasNext = True
next = 20, hasNext = False


                    7
                  /   \
                 3     \
                /  \    10
               2    6   /
              /    /   9
____________ 1    5   /
node to     |    /   3
extreme left|   4
------------

|1|
|2|
|3|
|7|
---
stack


now next->1
    next->2
    next->3
    (if has right push all right up to extreme left)

|4|
|5|
|6|
|7|
---
stack




*/

class Node {
public:
    int value;
    Node* left, *right;
    Node(int data) {
        this->value = data;
        this->left = this->right = NULL;
    }
};

class BSTIterator {
    stack <Node*> myStack;
    void pushAll(Node* node){
        for (; node; myStack.push(node),node = node->left);
    }

public:
    BSTIterator(Node* root) {
        pushAll(root);
    }
    bool hasNext() {
        return !myStack.empty();
    }
    int next(){
        Node* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->value;
    }
};

int main() {

}
