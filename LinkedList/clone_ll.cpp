#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* random;
        Node(int value) {
            val = value;
            next = NULL;
            random = NULL;
        }
};
/* 
Clonning the LL

Method 1 : Iterative copy  (by using unordered map)
TC = O(N)       SC = O(N) 

Method 2 : Optimized
    Create cone list
    Clone Note add b/w original list 
    Random ptr Copy
    Revert changes dome in step 2
    Return ans 

 */

Node* copyRandom_method1(Node* head){
    unordered_map <Node* , Node*>  hashmap ; 
    Node* temp = head;
    while(temp!= NULL){
        hashmap[temp] = new Node(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp!= NULL){
        hashmap[temp]->next = hashmap[temp->next];
        hashmap[temp]->random = hashmap[temp->random];
        temp = temp->next;
    }
    return hashmap[head];
}

Node* copyRandom_method2(Node* head){
    /* 
        (TC): O(N) + O(N) + O(N) = O(N)
        The function iterates through the original list twice:
            First iteration: Creating new nodes and interweaving them with the original nodes (O(N)).
            Second iteration: Setting random pointers for the new nodes (O(N)).
    Space Complexity (SC): O(1)
     */
    Node* temp = head;
    while(temp){ // step  1  &  2
        Node *newNode = new Node(temp->val);
        /* 
        ------------------------------
            temp  =   1*
            newNode = 1 -> 2 -> ---
                    head
            temp  =   1* -> 2

            newNode = 1 -> 1* ->  2 
         */
        newNode->next = temp->next;
        temp->next = newNode;
        // -----------------------------
        //      temp = 1 -> 1* ->  2 
        //                        head
        temp = temp->next->next;         }

    Node* dummy = new Node(0);
    Node* itr = head ;
    while (itr){
        /* 
        1 ===> 2 ===> 3
            ->1-> ->2->  ->3
            
            */
        if (itr->random) 
            itr->next->random = itr->random->next;
            itr = itr->next->next;       }

        // now all random & next is setup with but its along next now we have to remove rest part & take rest 
    itr = head ;
    temp = dummy ;
    while (itr){
        Node *fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }

    return dummy->next;
        
}

void printList(Node* head) {
    while(head != NULL) {
        cout<<head->val<<':';
        head->next != NULL ? cout<<head->next->val:cout<<"NULL";
        head->random != NULL ? cout<<","<<head->random->val:cout<<",NULL";
        cout<<endl;
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;
    
    head->random = node4;
    head->next->random = node1;
    head->next->next->random = nullptr;
    head->next->next->next->random = node2;
    
    cout << "Original list: (current node: node pointed by next pointer, node pointed by random pointer)" << endl;
    printList(head);
    
    cout << "Copy list: (current node: node pointed by next pointer, node pointed by random pointer)" << endl;
    Node* newHead = copyRandom_method2(head);
    printList(newHead);
    
    return 0;
}
