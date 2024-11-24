#include <iostream>
using namespace std;

/*
CIRCULAR QUEUE IMPLEMENT USING ARRAY 
 */
class Queue{
    int *arr;
    int start , end , curr_size , max_size;
public:
    Queue() : arr(new int[16]), start(-1), end(-1), curr_size(0) {}
    Queue(int size) : arr(new int[size]), start(-1), end(-1), curr_size(0), max_size(size) {}

    void push(int element) {
        if(curr_size == max_size) {
            cout << "Queue is full" << endl;
            return ;
        }
        if(start == -1) {
            start = 0;
            end = 0;
        }
        else     end = (end + 1) % max_size; // it is queue
        
        arr[end] = element;
        curr_size++;
    }
    int pop(){
        if (start == -1){
            cout << "queue empty"<< endl;
            return -1;}

        int popped = arr[start];
        if (curr_size == 1){
            start = -1;
            end = -1;
        }
        else start =( start + 1)%max_size; 
        curr_size--;
        return popped;
    }
    int top(){
        if (start == -1){
            cout << "queue empty";
            return -1;}
        return arr[start];
    }
    int size(){
        return curr_size;
    }

};


int main() {
    // Create a queue with default size
    Queue q1;

    // Push elements into the queue
    q1.push(10);
    q1.push(20);
    q1.push(30);

    // Print the top element
    cout << "Top element: " << q1.top() << endl;

    // Pop elements from the queue
    cout << "Popped element: " << q1.pop() << endl;
    cout << "Popped element: " << q1.pop() << endl;

    // Print the size of the queue
    cout << "Size of queue: " << q1.size() << endl;

    // Create a queue with custom size
    Queue q2(5);

    // Push elements into the queue
    q2.push(100);
    q2.push(200);
    q2.push(300);
    q2.push(400);
    q2.push(500);

    // Print the size of the queue
    cout << "Size of queue: " << q2.size() << endl;

    // Push one more element (queue is full)
    q2.push(600);

    return 0;
}