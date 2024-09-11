    /* 
    Appart from b.f. & hashing 3 - pointers can be applied
    To obtained space & TC
        for ( i->arr.size()-2 ){
            left=i+1;
            right=arr.size()-1;
            while(left<right){
                // rest 2-pointer (pair sum) completely
            }
            // return true inside loop return false outside
        }
    */
#include <iostream>
using namespace std;

class Node {
public:
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
    int data;
    Node *next, *prev;
};

Node* printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

bool find_triplet(Node* head, int target_sum) { // thsi deals with only sorte dll 
    Node* current = head;

    while (current->next != nullptr && current->next->next != nullptr) {
        Node* start = current->next;
        Node* end = head;
        int current_sum = target_sum - current->data;

        while (end->next != nullptr) // Move end pointer to the last node
            end = end->next;

        while (start != end && start && end ) {
            int pair_sum = start->data + end->data;

            if (pair_sum == current_sum) {
                cout << current->data << " " << start->data << " " << end->data << endl;
                return true;
            } else if (pair_sum < current_sum) {
                start = start->next;
            } else {
                end = end->prev;
            }
        }

        current = current->next;
    }

    return false;
}


Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

int main() {
    Node* head = nullptr;

    // Insert data in sorted order
    head = insert(head, 1);
    head = insert(head, 4);
    head = insert(head, 6);
    head = insert(head, 8);
    head = insert(head, 10);
    head = insert(head, 45);

    cout << "Original Doubly Linked List: ";
    printList(head);

    int target_sum = 22;

    cout << "Triplet with sum " << target_sum << ": ";
    if (!find_triplet(head, target_sum)) {
        cout << "No triplet found." << endl;
    }

    // Free memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}