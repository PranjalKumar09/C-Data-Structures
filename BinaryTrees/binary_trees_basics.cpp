#include<bits/stdc++.h>
 
/*

Not linear but hierachical data structure

    Ancestor -> of given node are all node come before node while traversing node to given node
    
    Sibling -> whoes parent are same
    
    Root -> top most where are hierachary beguns
    
    children -> one can parent or child
    
    subtree -> part of tree
    
    leafnode/descend -> doesnt have any child
    


Types

    Full Binary Tree : either 0 or 2 child

    Perfect BT : all leaf node on same level

    Degenerate BT : Like L.L.

    (Heap) Complete BT: all leves filled execpt last.  the last level musgt easch left as possible

    Balanced BT: Height should max-> log(N), N = no of node, ex-> n=8, log(8) = 3

    Strict BT: complete BT having either 0 or 2 offspring  .  Total = 2n - 1 
                                                n-> leafnode
                                                maxNode = 2^(n+1) - 1
                                                minNode = (2^n) + 1

Representation B.T.
    _______________________
    |    |           |    |     
    |    |   Value   |    |     
    |    |           |    |
    -----------------------



    L-> Left
    R-> Right
    N-> Node



Binary Tree Traversal
  i/p: node *root or Treenode *root

  Level Order
  Post Order  : LRN
  Inorder
  Pre Order   : NLR


Construct Unique B.T.
    Preorder : 123
    Postorder : 321
    1   |    1
   /    |   /
  2     |  2
 /      |   \ 
3       |    3

so not possible with preorder & postorder

    but with inorder and postorder only making unique is possible
            =====================================================

            


  */

int main(){}