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


bool detect_cycle(DoubleLinkedList *l1){
    // Check for empty or single node condition
    if (!l1->head || !l1->head->next) return true;

    Node *current = l1->head;

    while(current != nullptr){
        // If we encounter a node that has already been visited, there's a cycle
        if (current->data == -1) {
            return true; // Cycle detected
        }
        // Mark the current node as visited
        current->data = -1;
        // Move to the next node
        current = current->next;
    }

    return false; // No cycle detected
}


bool FloydCycleDetection(DoubleLinkedList *l1){
    // SC = O(1)
    // 2 pointer slow , fast if both meet then loop exist else no 
    // it is genrally recommended that fast should intialized with slow->next at starting to moves twice fast
    if (!l1->head ||  !l1->head->next) return false;
    Node *slow = l1->head;
    Node *fast = l1->head;

    // Check for empty or single node condition

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true; // Cycle detected
    }
    return false; // No cycle detected
}


/*

this mehtods fails in when cycle is other than from tail to head 

 bool detect_cycle(DoubleLinkedList *l1){
    // Check for empty or single node condition
    if (!l1->head || !l1->head->next) return true;

    Node *current = l1->head->next;

    while(current != nullptr){
        
        // If we reach back to the head node, there's a cycle
        cout << "current " << current -> data <<    "  l1->head-> data " << l1->head-> data  << endl;
        if (current == l1->head) {
            return true; // Cycle detected
        }

        /
        // Move to the next node
        current = current->next;
    }

    return false; // No cycle detected
}

 */



int main() {
    DoubleLinkedList list;

    // Create a cycle in the list (for demonstration purposes)

    // Detect cycle
    if (detect_cycle(&list))
        cout << "Cycle detected in the linked list." << endl;
    else
        cout << "No cycle detected in the linked list." << endl;

    // Remove the cycle only if the list is not empty
    if (list.head)
        list.tail->next = nullptr;

    return 0;
}
