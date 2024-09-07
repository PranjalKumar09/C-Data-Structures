#include <iostream>
using namespace std;

class Node {
public:
    Node (int data) : data(data) {}
    int data;
    Node *next , *prev;
};
 

/* 

FIND PAIRS WITH GIVEN SUM IN DLL

Method 1: B.F. Treat it like array then find sum
    for (i=0 -> n-1)
        for (j=i+1  -> n-1)

    TC = O(n)^2

Method 2: Hash Map
    key:value update in hash map check sum-n in hash ma[]
    value (frequency)
    TC = O(n)    |  SC = O(n)

Method 3: Two pointer approach
    TC = O(n)    |  SC = O(1)
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

void find_pair(Node* head, int  sum){
    Node *start = head;
    Node *end = head;

    while (end->next)
        end = end->next;

    bool found = false;
    while (start!= end){
        if (start->data + end->data == sum){
            cout << start->data << " " << end->data << endl;
            found = true;
            break;
        }
        else if (start->data + end->data < sum)
            start = start->next;
        else
            end = end->prev;
    }

    if (!found) cout << "Not found " << endl;
}


int main() {
    // Create a sample doubly linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(4);
    Node* fourth = new Node(5);
    Node* fifth = new Node(7);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    cout << "Original Doubly Linked List: ";
    printList(head);

    // Find pairs with a given sum
    int sum = 9;
    cout << "Pairs with sum " << sum << ": ";
    find_pair(head, sum);

    // Free memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
