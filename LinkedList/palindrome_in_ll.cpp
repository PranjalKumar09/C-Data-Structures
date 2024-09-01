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
Palindrome in LL


Method 1 : Convert LL to array, then check Palindrome 

Method 2 : 
Find middle 
Revers LL after middle
Compare both parts
Repeat 2nd step : this doesn't affect answer but help to keep original LL 
 */



bool Method1(DoubleLinkedList& ip){
    vector<int> arr;
    Node *temp = ip.head;
    while(temp!= nullptr){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int s = 0 , e = arr.size() - 1;
    while (s <= e)
        if (arr[s++]!= arr[e--]) return false;
    
    return 1 ;
}



//  Method 2
Node* middle_element(Node* &node) { 
    // TC = O(n/2)     SC = O(1)
    Node* slow = node, *fast = node;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node* reverseNode(Node* &ip){
    Node *prev = nullptr;
    Node *curr  = ip;
    while (curr){
        Node* temp   = ip -> next;
        ip -> next = prev;
        prev = ip;
        ip = temp;
    }
    return prev; 
}

bool Method2(DoubleLinkedList& ip) {
    Node *temp = ip.head;
    Node *middle = middle_element(temp); 
    middle->next = reverseNode(middle->next);
    while (temp && middle->next) {
        if (temp->data != middle->next->data) 
            return false;
        temp = temp->next;
        middle = middle->next;
    }
    return true;
}

int main() {
    // Create a linked list
    DoubleLinkedList dll;

    // Insert elements into the doubly linked list
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(2);
    dll.insertAtTail(1);

    // Print the original list
    cout << "Original list: ";
    dll.PrintDLL();

    // Check if the list is a palindrome using Method2
    if (Method2(dll)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    return 0;
}
