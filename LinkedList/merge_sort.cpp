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

 */



Node* getmid(Node *head){  // must create good mid node finding function
        if (!head || !head->next) return head; 
        Node *slow = new Node(-1) ;
        Node *fast = new Node(-1);
        slow -> next = head;
        fast -> next = head -> next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout << slow->data;
            return slow;
    }

Node *merge(Node*left, Node*right){
    if (!left) return right;
    if (!right) return left;

    Node *result = new Node(-1);
    Node *temp = result;
    while (left && right){
        if (left->data < right->data){
            temp->next = left;
            temp = left; // if DL include left->prev = temp also  (above this line)
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right; // if DL include right->prev = temp also  (above this line)
            right = right->next;
        }
    }
    while (left){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    return result->next;
}

Node* mergesort(Node* head){
    if (!head || !head->next)return head;
    Node* mid = getmid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    left = mergesort(left);
    right = mergesort(right);
    return merge(left, right);
}


Node* printList( Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
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
    head = mergesort(head);

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
