#include <iostream>
using namespace std;

class Node {
public:
    Node (int data) : data(data) {}
    int data;
    Node *next, *bottom;
};
 

/* 

FLATTEN LL

Method 1: Go to each element by storing in new LL(n*m) then merge then O(n)
SC => O(n)          TC = O(n) + O(n*m)

Method 2: Change in same LL by this same space 
 */



Node* printList( Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

Node *merge(Node*left, Node*right){

    if (!left) return right;
    if (!right) return left;

    Node *result = new Node(-1);
    Node *temp = result;
    while (left && right){
        if (left->data < right->data){
            temp->bottom = left;
            temp = left; // if DL include left->prev = temp also  (above this line)
            left = left->bottom;
        }
        else{
            temp->bottom = right;
            temp = right; // if DL include right->prev = temp also  (above this line)
            right = right->bottom;
        }
    }
    while (left){
        temp->bottom = left;
        temp = left;
        left = left->bottom;
    }
    while (right){
        temp->bottom = right;
        temp = right;
        right = right->bottom;
    }
    return result->bottom;
}

void downToNext(Node* &head) {// we assumed that list have no next 
    Node* current = head;   
    Node* previous = nullptr; // Initialize previous node for each iteration
    // Traverse through the list
    
    // Traverse vertically and update next pointers
    while (current) {
        if (current->bottom) {
            current->next = current->bottom; // Update next pointer
            previous = current->next; // Update previous node for the next iteration
        }
        current = current->bottom; // Move vertically
    }
    // Move horizontally to the next node      
}






Node* method1(Node* head){

    Node* temp = head;
    while(temp && temp->bottom){
        temp = merge(temp, temp->next);
        temp = temp->next;
    }
    downToNext(head);
    return head;
}



Node* method2(Node* head){
    if (!head || !head->next) return head;
    head->next = method2(head->next);
    head = merge(head, head->next);
    downToNext(head);
    return head;
}


int main() {
    // Creating sample linked list
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next->bottom = new Node(20);

    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);


    // Call method1 to flatten the linked list

    head = method2(head);

    // Print the flattened linked list
    printList(head);

    return 0;
}
