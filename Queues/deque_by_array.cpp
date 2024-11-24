#include <iostream>
using namespace std;

/* 
    DEQUEUE IMPLEMENTATION USING ARRAY
 */


class Deque {
    int *arr, front , rear, size ;
    public:
    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    bool isFull() { return ((front == 0) && rear == size-1) || front == rear +1; }
    void insert_front(int key){
        if (isFull())  {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) 
            front = rear = 0;
        else if (!front && rear!= size-1) front = size-1; // flexible array
        
        else front--;
        arr[front] = key;
    }
    void insert_rear(int key){
        if (isFull())  {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) 
            front = rear = 0;
        else if (front!= 0 && rear == size-1) rear = 0; // flexible array
        else rear++;
        arr[rear] = key;
    }
    int pop_front(){
        if (is_empty()) return -1;
        int key = arr[front];
        arr[front] = -1;
        if (front == rear) front = rear = -1;
        else if (front == size-1) front = 0;
        else front++;
        return key;
    }
    int pop_rear(){
        if (is_empty()) return -1;
        int key = arr[rear];
        arr[rear] = -1;
        if (front == rear) front = rear = -1;
        else if (rear == 0) rear = size-1;
        else rear--;
        return key;
    }
    int get_front(){
        if (is_empty()) return -1;
        return arr[front];
    }
    int get_rear(){
        if (is_empty()) return -1;
        return arr[rear];
    }
    bool is_empty(){
        return front == -1;
    }
};


int main() {
    Deque dq(5);

    dq.insert_rear(5);
    dq.insert_rear(10);
    cout<< "Rear element: "<< dq.get_rear()<< endl; // Should print 10

    dq.insert_front(15);
    cout<< "Front element: "<< dq.get_front()<< endl; // Should print 15

    dq.pop_rear();
    cout<< "After deleting rear element, new rear is: "<< dq.get_rear()<< endl; // Should print 5

    dq.pop_front();
    cout<< "After deleting front element, new front is: "<< dq.get_front()<< endl; // Should print 5

    dq.insert_front(20);
    dq.insert_rear(25);
    cout<< "Front element: "<< dq.get_front()<< endl; // Should print 20
    cout<< "Rear element: "<< dq.get_rear()<< endl; // Should print 25

    return 0;
}