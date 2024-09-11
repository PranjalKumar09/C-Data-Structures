#include <iostream>
#include <queue>
using namespace std;

/* 
SORT k SORTED DOUBLY LL

    
    
3 <---> 6 <---> 2 <---> 6 <---> 56 <---> 8   k =  2
|_______________^_______________| 
i-k                            i+k


priority-queues (k+1) 
(min-heap)

Already Sorted              Unsorted 
------------------------i------->
        |_______________^_______________| 
        i-k                            i+k
        |______________||_______________|
        (k)              (k+1)
    
 */

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

struct compare {
    bool operator()(const Node* a, const Node* b) {
        // Compare based on the data of the nodes
        return a->data > b->data; // Change the comparison logic if needed
    }
};


void Print(Node *node){
    while(node){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

Node* Sort_k_sorted_doubly_ll(Node *head, int k){
    if (!head) return head;
    priority_queue <Node* , vector<Node*>, compare > pq;
    
    Node *newHead = nullptr, *cur = nullptr;
    for (int i = 0; head && i <= k ; i++) {
        pq.push(head);
        head = head->next;}
    
    while( !pq.empty()){
        if (newHead == nullptr) {
            newHead = pq.top();
            cur = newHead;
            pq.pop();
        }
        else{
            cur->next = pq.top();
            cur->next->prev = cur;
            cur = cur->next;
            pq.pop();
        }
        if (head){
            pq.push(head);
            head = head->next;
        }    }
    cur->next = nullptr;
    return newHead;
}

int main() {
    // Create a sample linked list
    Node* head = new Node(3);
    head->next = new Node(6);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(12);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(56);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    cout << "Original list: ";
    Print(head);

    int k = 2; // k-sortedness parameter

    Node* sortedHead = Sort_k_sorted_doubly_ll(head, k);

    cout << "Sorted list: ";
    Print(sortedHead);

    // Clean up dynamically allocated memory
    Node* temp;
    while (sortedHead) {
        temp = sortedHead;
        sortedHead = sortedHead->next;
        delete temp;
    }

    return 0;
}