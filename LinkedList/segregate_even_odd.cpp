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

void Segregate_even_odd(DoubleLinkedList &list){
    /* 
    TC = O(n)
    SC = O(1)

    Segreating LL in 2 list by pointer
        ES       ->        EE       ->          OS      ->         OE
        Even Start      Even End             Odd Start             Odd End


    (Check after main process) 
    Explict Condtion: if no even exist return odd start
                      if (OE)   OE  =  OE -> next = null;
                      if no odd exist     return even_start;    
     
     
     */

    if (!list.head ||  !list.head->next  ) return;


    // intiliaztion
    Node* odd_head = nullptr;  
    Node* even_head = nullptr;
    Node* odd_tail = nullptr;
    Node* even_tail = nullptr;

    Node* temp = list.head;
    while(temp){
        int data = temp->data;

        // for odd
        if (data % 2){
            if (odd_head == nullptr){
                odd_head = temp;
                odd_tail = temp;
            }
            else{
                odd_tail->next = temp;
                // temp->prev = odd_tail; // optional
                odd_tail = temp;
            }
        }
        // for even
        else {
            if (even_head == nullptr){
                even_head = temp;
                even_tail = temp; }
            else{
                even_tail->next = temp;
                // temp->prev = even_tail; // optional
                even_tail = temp;
            }}
        temp = temp -> next;
        }
    if (odd_tail) odd_tail -> next = nullptr;  // setting last next to nullptr
    if (!even_head) even_head  = odd_head ;// only odd case 
    else even_tail->next = odd_head;
    list.head = even_head;
    }


int main() {
    DoubleLinkedList list;

     // Insert elements into the list
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);

    list.PrintDLL();

    Segregate_even_odd(list);

    list.PrintDLL();

    
    
    return 0;
}
