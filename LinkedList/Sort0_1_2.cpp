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
        while(temp->next){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
        cout << endl;
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


/*
Method 1 :Count 0,1,2 then replace data (Initliaze with 0)

Then while allocating 0,1,2 & decrease the num t0 0.First 0, then 1 , then 2
TC = O(2N)



Method 2 : Without data replacement (when said)
Make 3 LL each for 0,1,2 
Head 0 -> Tail 0 -> Head 1 -> Tail 1 -> Head 2 -> Tail 2 



// SC  = O(1)
TC = O(N)
  */

void Sort012(DoubleLinkedList& ip) {
    if (!ip.head || !ip.head->next) return;

    Node *current = ip.head;
    Node *head0 = nullptr, *head1 = nullptr, *head2 = nullptr;
    Node *tail0 = nullptr, *tail1 = nullptr, *tail2 = nullptr;

    while (current) {
        Node* nextNode = current->next;  // Store the next node before modifying current
        current->next = nullptr;  // Break the link to the next node

        // Determine which list (0, 1, or 2) the current node belongs to
        if (current->data == 0) {
            if (!head0) {
                head0 = current;
                tail0 = current;
            } else {
                tail0->next = current;
                tail0 = current;
            }
        } else if (current->data == 1) {
            if (!head1) {
                head1 = current;
                tail1 = current;
            } else {
                tail1->next = current;
                tail1 = current;
            }
        } else { // current->data == 2
            if (!head2) {
                head2 = current;
                tail2 = current;
            } else {
                tail2->next = current;
                tail2 = current;
            }
        }

        current = nextNode;  // Move to the next node
    }

    // Connect the three lists (0, 1, and 2) together
    if (head0) {
        ip.head = head0;
        tail0->next = head1 ? head1 : head2;
    } 
    tail1->next = head2; 
    
}



int main() {
    // Create a linked list
    DoubleLinkedList dll;

    // Insert elements into the doubly linked list
    dll.insertAtTail(1);
    dll.insertAtTail(0);
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    dll.insertAtTail(0);

    // Print the original list
    cout << "Original list: ";
    dll.PrintDLL();

    // Sort the list
    Sort012(dll);

    cout << "Sorted list: ";
    // Print the sorted list
    dll.PrintDLL();

    return 0;
}
