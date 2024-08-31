#include <iostream>
using namespace std;

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
class DoubleLinkedList{
    public:    
    Node *head , *tail;
    DoubleLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~DoubleLinkedList(){
    Node *temp = head;
    while(temp != nullptr){
        head = head->next;
        delete temp;
        temp = head;
    }
}

    void insertAtHead(int data){
        Node *newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtTail(int data){
        Node *newNode = new Node(data);
        if (tail == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insertAtPosition(int data, int position) {
        if (position == 0)  insertAtHead(data);
        else {
        Node* newNode = new Node(data);
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position" << endl;
            delete newNode; // Clean up the memory allocated for the new node
            return;
        }

        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }}
    void PrintDLL(){
        if (head == nullptr) cout << "Invalid head" << endl;
        Node *temp = head;
        while(temp->next ){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " " << endl;
    }
    void Delete_Node(int data){
        Node *temp = head;
        while(temp!= nullptr && temp->data!= data)
            temp = temp->next;
        
        if(temp == nullptr){
            cout << "Node not found" << endl;
            return;}
        
        if(temp == head)
            head = head->next;
        
        if(temp == tail)
            tail = tail->prev;
        
        if(temp->prev!= nullptr)
            temp->prev->next = temp->next;
        
        if(temp->next!= nullptr)
            temp->next->prev = temp->prev;
        
        delete temp;
    }
    void Reverse(){
        if (head == nullptr || head->next == nullptr)
            return;

        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr){
            temp = current->prev;

            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        head = temp->prev;
        head->prev = nullptr;
}
    int  getLength(){
        Node *temp = head;
        int count = 0;
        while(temp!= nullptr && temp->next && temp->next != head){
            count++;
            temp = temp->next;
        }
        if (temp->next == head) return -1;
        return count;
    }
   

};

// sorted 
DoubleLinkedList remove_duplicate(DoubleLinkedList & head) {
    DoubleLinkedList result;
    if (!head.head) return result;
    Node *curr = head.head;
    Node *resultCurr = nullptr;
    while (curr) {
        if (!result.head) {
            result.insertAtTail(curr->data);
            resultCurr = result.head;
        } else if (curr->data != resultCurr->data) {
            resultCurr->next = new Node(curr->data);
            resultCurr = resultCurr->next;
        }
        curr = curr->next;
    }
    return result;
}

int main() {
    // Create a linked list
    DoubleLinkedList dll;
    dll.insertAtHead(1);
    dll.insertAtHead(2);
    cout << "Initial List:" << endl;
    dll.PrintDLL(); // Print the initial list
    dll.insertAtHead(3);
    dll.insertAtTail(4);
    dll.insertAtTail(5);
    dll.insertAtTail(4);

    // Print the list before removing duplicates
    cout << "List before removing duplicates:" << endl;
    dll.PrintDLL();

    // Remove duplicates
    DoubleLinkedList modifiedList = remove_duplicate(dll);

    // Print the modified list after removing duplicates
    cout << "List after removing duplicates:" << endl;
    modifiedList.PrintDLL();



    return 0;
}
