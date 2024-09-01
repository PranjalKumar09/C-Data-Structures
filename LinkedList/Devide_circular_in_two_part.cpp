#include <iostream>
#include<vector>
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
    Node *start = getStartNode(temp);
    Node *temp2 = start;
    while (temp2 -> next != start) {
        
        
        temp2 = temp2 -> next;}
    
    list.tail = temp2->next;
    list.tail->next = nullptr;    
} 

vector<DoubleLinkedList> Divide_circular(DoubleLinkedList& dll) {
    if (!dll.head || !dll.head->next || dll.head->next == dll.head) 
        return {dll, DoubleLinkedList()};

    if (detect_loop(dll.head)) {
        Delete_loop(dll);
        dll.tail->next = nullptr;
    }

    Node *slow = dll.head;
    Node *fast = dll.head->next;

    vector<DoubleLinkedList> list(2);
    Node *l1_tail = nullptr;
    Node *l2_tail = nullptr;

    while (fast && fast->next) {
        if (!list[0].head) {
            list[0].head = new Node(slow->data);
            l1_tail = list[0].head;
        } else {
            l1_tail->next = new Node(slow->data);
            l1_tail->next->prev = l1_tail;
            l1_tail = l1_tail->next;
        }

        if (!list[1].head) {
            list[1].head = new Node(fast->data);
            l2_tail = list[1].head;
        } else {
            l2_tail->next = new Node(fast->data);
            l2_tail->next->prev = l2_tail;
            l2_tail = l2_tail->next;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    // Add the last nodes
    if (slow) {
        l1_tail->next = new Node(slow->data);
        l1_tail->next->prev = l1_tail;
        l1_tail = l1_tail->next;
    }
    if (fast) {
        l2_tail->next = new Node(fast->data);
        l2_tail->next->prev = l2_tail;
        l2_tail = l2_tail->next;
    }

    // Update tails
    list[0].tail = l1_tail;
    list[1].tail = l2_tail;

    return list;
}



int main() {
    // Create a circular linked list
    DoubleLinkedList circularList;
    circularList.insertAtHead(1);
    circularList.insertAtHead(2);
    circularList.insertAtHead(3);
    circularList.insertAtTail(4);
    circularList.insertAtTail(5);
    circularList.insertAtTail(6);


    // Create a cycle in the list (for demonstration purposes)
    circularList.tail->next = circularList.head->next;

    // Divide the circular list into two halves
    vector<DoubleLinkedList> dividedLists = Divide_circular(circularList);

    // Print the two divided lists
    cout << "First half of the circular list:" << endl;
    dividedLists[0].PrintDLL();

    cout << "Second half of the circular list:" << endl;
    dividedLists[1].PrintDLL();

    circularList.tail->next = nullptr;

    

    return 0;
}
