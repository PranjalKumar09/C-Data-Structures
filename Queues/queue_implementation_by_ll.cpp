#include <iostream>

using namespace std;

/*
QUEUE IMPLEMENTATION BY LL
*/

class node{
public:
    int data;
    node* next;
    node(int data) : data(data), next(NULL) {}
};

class Queue{
    node* front;
    node* back;

public:
    Queue() : front(NULL), back(NULL) {}

    void push(int x){
        node *n = new node(x);
        if (!back) {
            front = back = n;
        } else {
            back->next = n;
            back = n;
        }
    }

    void pop(){
        if (!front) {
            cout << "Queue Underflow" << endl;
            return;
        }
        node *toDelete = front;
        front = front->next;
        if (!front) {
            back = NULL;
        }
        delete toDelete;
    }

    int peek() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // Should print 1

    q.pop();
    cout << "Front element after pop: " << q.peek() << endl; // Should print 2

    q.pop();
    cout << "Front element after another pop: " << q.peek() << endl; // Should print 3

    q.pop();
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Should print Yes

    q.pop(); // Should indicate that the queue is empty

    return 0;
}
