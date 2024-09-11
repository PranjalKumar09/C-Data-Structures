#include <iostream>
#include <queue>
using namespace std;

/* 
ROTATE DOUBLY LL BY N NODES 

i/p : 1 -> 2 -> 3 -> 4 -> 5    n = 2
o/p : 3 -> 4 -> 5 -> 1 -> 2 
*/

struct Node{
    int data;
    Node *next , *prev;

    Node(){
        data = -1;
        next = NULL;
        prev = NULL;
    }
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }

};



void Rotate_doubly_LL_by_N_nodes(Node * &head, int n){
    if (!n) return ;
    Node *cur = head;
    int count = 1;
    while ( count < n && cur){
        cur = cur->next;
        count++; 
    } 
    Node* NthNode = cur;
    while (cur->next)
        cur = cur->next;
     
    cur -> next = head ; // connecting DLL
    head -> prev = cur;

    head = NthNode -> next;
    head -> prev = nullptr;
    NthNode -> next = nullptr;

}
void Print(Node *node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Create a sample doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original list: ";
    Print(head);

    int n = 2; // Number of nodes to rotate

    // Rotate the list
    Rotate_doubly_LL_by_N_nodes(head, n);

    cout << "List after rotating by " << n << " nodes: ";
    Print(head);

    // Clean up dynamically allocated memory
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}