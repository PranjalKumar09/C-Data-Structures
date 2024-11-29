#include <iostream>
using namespace std;

/* 
    QUEUE IMPLEMENTATION USING ARRAY
 */


class Queue {
    int *arr;
    int qfront, rear, size;
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    ~Queue() {
        delete[] arr;
    }
    bool isEmpty() {
        return (qfront == rear);
    }
    void enqueue(int data) {
        if ((rear + 1) % size == qfront) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = data;
        rear = (rear + 1) % size;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront = (qfront + 1) % size;
        return ans;
    }
    int front() {
        if (isEmpty()) return -1;
        return arr[qfront];
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << q.dequeue() << endl; // 10
    cout << q.front() << endl;   // 20
    return 0;
}
