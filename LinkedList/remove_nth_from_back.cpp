#include <iostream>
using namespace std;


/* 

REMOVE N-th NODE FORM END OF LL
ip: [1,2,3,4,5]    n = 2
op: [1,2,3,5]


METHOD 1: Transervers 2 tiems for counting & to get nth node from back

METHOD 2: 2 pointer approach
    * 2 Dummy nodes like => dummy->next=head;
    * slow = fast = dummy
    * for (i = 1->n) fast=fast->next
    
                    <------><-------------->
                        n     N-n
    
                    
    * while(){fast = fast->next
              slow = slow->next}
                    <---------------------->
                            N

                    <--------------><------>
                         N-n           n

    * slow->next = slow->next->next
    * return dummy->next
 */

struct Node{
    int data;
    Node *next;

    Node(){
        data = -1;
        next = NULL;
    }
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* head){
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void Remove_nth_from_end(Node* head, int n){
    Node* dummy = new Node();
    dummy->next = head;
    Node* slow = dummy;
    Node* fast = dummy;
    for (int i = 1; i <= n; i++) 
        fast = fast->next;
    
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    printList(dummy->next);
}


int main() {
    // Creating a linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Printing the original linked list
    cout << "Original Linked List: ";
    printList(head);

    // Removing the 2nd node from the end
    int n = 2;
    Remove_nth_from_end(head, n);

    // Printing the modified linked list
    cout << "Linked List after removing " << n << "th node from the end: ";
    printList(head);

    return 0;
}
