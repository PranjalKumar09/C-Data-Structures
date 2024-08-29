/* 
It is not possible to reverse in less than TC O(N)





 */

#include <iostream>
using namespace std;



class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* n1) : data(data), next(n1) {}

    ~Node() {
        cout << "Deleting Node with data: " << data << endl;
        delete next;
    }

    void insertAtTail(Node*& tail, int d) {
        Node* temp = new Node(d);
        if (!tail)
            tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void insertAtHead(Node*& head, int d) {
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }

    void insertAtPostion(Node*& head, int postion, int data) {
        if (postion <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (postion == 1) {
            insertAtHead(head, data);
            return;
        }

        Node* temp = head;
        int cnt = 1;
        while (cnt < postion - 1 && temp->next) {
            temp = temp->next;
            cnt++;
        }
        Node* NodeToInsert = new Node(data);
        NodeToInsert->next = temp->next;
        temp->next = NodeToInsert;

        if (!NodeToInsert->next) // Update tail if necessary
            tail = NodeToInsert;
    }

    void deleteNode(int position, Node*& head) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            temp->next = nullptr; // Remove the connection to avoid deletion of subsequent nodes
            delete temp;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        int cnt = 1;
        while (cnt < position && curr) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (!curr) {
            cout << "Position exceeds list length!" << endl;
            return;
        }

        prev->next = curr->next;
        curr->next = nullptr; // Remove the connection to avoid deletion of subsequent nodes
        delete curr;
    }

    int getLength() {
        int len = 0;
        Node* temp = this->next;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void printList(Node* node) {
        Node* temp = node;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* tail = nullptr; // Added to keep track of tail
};


// Brute force
Node* middle_element_1(Node* &node){ 
    // TC = O(n) +  O(n/2)   =   O(3n/2)
    int len = (node->getLength())/2;
    Node *temp = node;    
    while (len){
        temp = temp->next;
        len--;
    }
    return temp;
}


// OS Tortise Hare Algorithm
Node* middle_element_2(Node* &node){ 
    // TC = O(n/2)     SC = O(1)
    Node* slow = node , *fast = node ;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;}
    return slow;
}


    
int main(){
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Find the middle element using brute force approach
    Node* middle1 = middle_element_1(head);
    cout << "Middle element (Brute force): " << middle1->data << endl;

    // Find the middle element using Tortoise and Hare algorithm
    Node* middle2 = middle_element_2(head);
    cout << "Middle element (Tortoise and Hare): " << middle2->data << endl;

    // Clean up memory
    delete head;

    return 0;
}
