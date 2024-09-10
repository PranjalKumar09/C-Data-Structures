// NOT DONE 


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
    void insertAtHead(Node* newNode) {
        if (!newNode) {
            cout << "Invalid node. Cannot insert." << endl;
            return;
        }
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtTail(Node* newNode) {
        if (!newNode) {
            cout << "Invalid node. Cannot insert." << endl;
            return;
        }
        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
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
    if (temp != nullptr)
        head = temp->prev;
    while (head->prev != nullptr)
        head = head->prev;
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
    DoubleLinkedList operator+(DoubleLinkedList& d2){
        
        if (!head) return d2;
        if (!d2.head) return *this;
        // first reverse both LL
        DoubleLinkedList d3;
        this->Reverse();
        Node *head1 = this->head;
        d2.Reverse();
        Node *head2 = d2.head;
        int carry = 0;
        while (head1 || head2 || carry){
            int sum = 0;
            if (head1){
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2){
                sum += head2->data;
                head2 = head2->next;
            }
            sum+=carry;
            carry = sum/10;
            d3.insertAtHead(sum%10);
        }
        // cout << "checking" << endl;
            d3.PrintDLL();
        return d3;
    }

};

int main() {
    // Create two DoubleLinkedList objects
    DoubleLinkedList d1, d2;

    // Insert elements into the first list
    d1.insertAtTail(1);
    d1.insertAtTail(2);
    d1.insertAtTail(3);

    // Insert elements into the second list
    d2.insertAtTail(5);
    d2.insertAtTail(6);

    // Print the original lists
    cout << "Original list 1: ";
    d1.PrintDLL();
    cout << "Original list 2: ";
    d2.PrintDLL();

    // Perform addition operation using the overloaded + operator
    DoubleLinkedList sum = d1 + d2;

    // Print the result of the addition
    cout << "Sum of the lists: " << endl ;


    return 0;
}
