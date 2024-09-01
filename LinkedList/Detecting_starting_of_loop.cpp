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
        while(temp!= nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
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

Distance by fast = 2 * (Distance by slow)

A + x * C + B    = 2 * (A + B + y * C)
C(x-2y)          = A + B
A + B = kC      ( Completing cycle )

A is distance from head to cycle starts
B is distance form cycle starts and point of inersection 
C is distance of complete cycle 



1) Check loop
2) Get start
3) Remove loop

 */





Node* getIntersection(Node* ip){
    Node *slow = ip->next;
    Node *fast = ip->next->next;
    while(slow!= fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    }

Node* getStartNode(Node* ip){
    Node* intersection = getIntersection(ip);
    Node *slow  =  ip;

    while (slow!= intersection){
        slow = slow->next;
        intersection = intersection->next->next;
    }
    return slow; // get start node of loop
}

bool detect_loop(Node* ip){
    if (!ip || !ip->next) return false;
    Node *slow = ip;
    Node *fast = ip->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
            return true;       
            
    }
    return false;
}


void Delete_loop(DoubleLinkedList &list){ // we can also do it by changing one by one bit
    Node *temp = list.head;
    if (!detect_loop(temp)) {
        cout << "No loop detected" << endl;
        return;
    }
    Node *start = getStartNode(temp);
    Node *temp2 = start;
    while (temp2 -> next != start) {
        
        
        temp2 = temp2 -> next;}
    
    list.tail = temp2->next;
    list.tail->next = nullptr;    
} 





int main() {
    // Create a linked list
    DoubleLinkedList dll;
    dll.insertAtHead(1);
    dll.insertAtHead(2);
    dll.insertAtHead(3);
    dll.insertAtTail(4);
    dll.insertAtTail(5);
    dll.insertAtTail(6);

    // Dont print at starting it will do 
    dll.tail->next = dll.head->next;

    // Detect and delete the loop
    Delete_loop(dll); 
    dll.PrintDLL();

    dll.tail->next = nullptr;

    return 0;}