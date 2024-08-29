/* 
It is not possible to reverse in less than TC O(N)





 */

#include <iostream>
using namespace std;

    class Node{
        public:
        int data;
        Node *next;

        Node() : data(0) , next(nullptr) {} 

        Node(int data) : data(data) , next(nullptr) {}

        Node(int data, Node *n1) : data(data), next(n1) {}

        void print(){
            Node* temp = next;
            cout << this -> data << " ";
            while(temp!= nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };
    
void reverse_list(Node * &head){ // TC = O(N)     SC = O(1)
    Node *prev = nullptr;
    Node *curr = head;
    while(curr != nullptr){
        Node *forward = curr-> next;  // by this list is procedding foraward
        curr->next = prev;  // Doing the reverse 
        prev = curr;        // These 2 line are doing reverse  
        curr = forward;     // this is iterating loop effetively
    }
    head = prev;
}    



// recursive
Node* reverse_list_recursive(Node * &head){ // TC = O(N) SC = O(1) 
// in this remember take    Node *    not  just    Node
    if (!head || !head->next )
    return head;
    Node* reversed_Node = reverse_list_recursive(head->next); // calling recursively reverse
    head->next->next = head;
    head->next = nullptr;
    return reversed_Node; // when it returns at that time all list will have reversed 
/*
    // Doing this step through out the process
     ___________         ___________             ___________         ___________
    |           |       |           |           |           |       |           |
    |   head    |------>|    next   |---------->|    head   |------>|    null   |
    |___________|       |___________|           |___________|       |___________|

    =>

            ___________             ___________ 
           |           |           |           |
    <------|    head   |<----------|    next   |
           |___________|           |___________|

*/
}

    
    

    
    
    
int main(){
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    head->print();

    head = reverse_list_recursive(head);
    cout << "Reverse Linked List: ";
    head->print();

        
    
    return 0;
}