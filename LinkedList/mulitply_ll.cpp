#include <iostream>
using namespace std;

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

Node* multiply_two_ll(Node* a, Node* b){
    long long num1 = 0 , num2 = 0;
    while (a||b){
        if (a){
            num1 = num1*10 + a->data;
            a = a->next;
        }
        if (b){
            num2 = num2*10 + b->data;
            b = b->next;
        }
    } 
    long num3 = num1*num2;
    Node* head = NULL;
    while (num3){
        Node* temp = new Node(num3%10);
        temp->next = head;
        head = temp;
        num3 = num3/10;
    }
    return head;
}



int main() {
    // Creating linked lists representing numbers
    Node* a = new Node(9);
    a->next = new Node(4);
    a->next->next = new Node(6);

    Node* b = new Node(8);
    b->next = new Node(5);

    // Printing the input linked lists
    cout << "Linked List A: ";
    printList(a);
    cout << "Linked List B: ";
    printList(b);

    // Multiplying the linked lists
    Node* result = multiply_two_ll(a, b);

    // Printing the result linked list
    cout << "Result: ";
    printList(result);

    return 0;
}