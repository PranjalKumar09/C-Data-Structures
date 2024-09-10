#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *next;

    Node(){
        data = -1;
        next = NULL;
    }
    Node(int x){
        data = x;
        next = NULL;
    }
};

/* 
TC = avg/best: O(N * log N)
SC = O(N)

by using Node**, the partition function can effectively update the head and end pointers of the linked list, allowing for proper partitioning and sorting of the list.


 */
Node* getTail( Node* cur) 
{ 
    while (cur != NULL && cur->next != NULL) 
        cur = cur->next; 
    return cur; 
} 

void printList(Node* head){
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* partition( Node* head,  Node* end, 
                        Node** newHead, 
                        Node** newEnd) { 
     Node* pivot = end; 
     Node *prev = NULL, *cur = head, *tail = pivot; 
  
    // During partition, both the head and end of the list 
    // might change which is updated in the newHead and 
    // newEnd variables 
    while (cur != pivot) { 
        if (cur->data < pivot->data) { 
            // First node that has a value less than the 
            // pivot - becomes the new head 
            if ((*newHead) == NULL) 
                (*newHead) = cur; 
  
            prev = cur; 
            cur = cur->next; 
        } 
        else // If cur node is greater than pivot 
        { 
            // Move cur node to next of tail, and change 
            // tail 
            if (prev) 
                prev->next = cur->next; 
             Node* tmp = cur->next; 
            cur->next = NULL; 
            tail->next = cur; 
            tail = cur; 
            cur = tmp; 
        } 
    } 
  
    // If the pivot data is the smallest element in the 
    // current list, pivot becomes the head 
    if ((*newHead) == NULL) 
        (*newHead) = pivot; 
  
    // Update newEnd to the current last node 
    (*newEnd) = tail; 
  
    // Return the pivot node 
    return pivot; 
} 
  
// here the sorting happens exclusive of the end node 
 Node* quickSortRecur( Node* head, 
                             Node* end) 
{ 
    // base condition 
    if (!head || head == end) 
        return head; 
  
    Node *newHead = NULL, *newEnd = NULL; 
  
    // Partition the list, newHead and newEnd will be 
    // updated by the partition function 
    Node* pivot  = partition(head, end, &newHead, &newEnd); 
  
    // If pivot is the smallest element - no need to recur 
    // for the left part. 
    if (newHead != pivot) { 
        // Set the node before the pivot node as NULL 
         Node* tmp = newHead; 
        while (tmp->next != pivot) 
            tmp = tmp->next; 
        tmp->next = NULL; 
  
        // Recur for the list before pivot 
        newHead = quickSortRecur(newHead, tmp); 
  
        // Change next of last node of the left half to 
        // pivot 
        tmp = getTail(newHead); 
        tmp->next = pivot; 
    } 
  
    // Recur for the list after the pivot element 
    pivot->next = quickSortRecur(pivot->next, newEnd); 
  
    return newHead; 
} 

int main() {
    // Create a linked list
    Node* head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    
    cout << "Original list: ";
    printList(head);
    
    // Sort the list
    Node* tail = getTail(head);
    head = quickSortRecur(head, tail);

    cout << "Sorted list: ";
    printList(head);
    
    // Clean up memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
