#include <iostream>
#include <vector>
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
    void insertAtTail(Node* &temp){
        if (!temp) return;
        if (head == nullptr){
            head  = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
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

Intersection in 2 Linked List
            1 -> 2 
                   -> 6 -> 7 -> null
       3 -> 5 -> 2 

    (Check node equal not node->data)



Method 1: Brute Force Iterative:    TC = O(N)^2
Method 2: Get length of Both LL simulatnseously -: TC = O(N)
    Node 1 (size=m) : 1 -> 2 -> 3 -> 4 -> 5
Common area                                -> 8 -> 9 -> 10 -> 11   
    Node 2 (size=n) :                6 -> 7
                      |_____________|
                            m-n 


    iterate bigger m-n times , then search each node equal while iterating next of each



 */




// TC = O(M-N)+O(N)+O(M)    (length - M-N steps ,M ,  N steps)
Node* method2( DoubleLinkedList& dll1 ,DoubleLinkedList& dll2  ){

    if (!dll1.head || !dll2.head) return nullptr;
    int len1 = dll1.getLength();
    int len2 = dll2.getLength();
    Node* larger , *smaller;

    if (len1 < len2) {
        larger = dll2.head ;
        smaller = dll1.head;
    }
    else {
        larger = dll1.head ;
        smaller = dll2.head;
    }

    int diff = abs(len1 - len2);
    while (diff){
        larger = larger->next ;
        diff--;
    }
    while (larger!= smaller){
        larger = larger->next;
        smaller = smaller->next;
        
    }
    return larger;
}



// TC = O(2M)   SC = O(1)
// Code is vey small so perferred 
Node* method3( DoubleLinkedList& dll1 ,DoubleLinkedList& dll2  ){
    if (!dll1.head || !dll2.head) return nullptr;
    Node * a = dll2.head ;
    Node * b = dll1.head ;

    while (a!= b){
    a=a==nullptr?dll2.head:a->next;
    b=b==nullptr?dll1.head:b->next;
    }
    return a;
}

void printNode(Node* &node) {
    if (node == nullptr) {
        cout << "Invalid node" << endl;
        return;
    }
    while (node){
    cout << node->data << endl;
    node = node->next;
}}


int main(){
    DoubleLinkedList d1 ,d2, d3;
    d1.insertAtTail(1);
    d1.insertAtTail(2);
    d1.insertAtTail(3);
    d1.insertAtTail(4);
    d1.insertAtTail(6);
    d2.insertAtTail(2);
    d2.insertAtTail(4);
    d2.insertAtTail(6);
    d2.PrintDLL();
    Node* n1 = new Node(7);
    Node* n2 = new Node(8);
    d3.insertAtTail(n1);
    d3.insertAtTail(n2);
    d1.tail -> next = d3.head;
    d2.tail -> next = d3.head;

    Node* answer  = method2(d1,d2);
    printNode(answer);


    // d1.PrintDLL();

    return 0 ;
    
    }