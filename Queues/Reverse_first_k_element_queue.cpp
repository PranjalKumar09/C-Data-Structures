#include <bits/stdc++.h>
using namespace std;

/* 
REVERSE FIRST K ELEMENT OF QUEUE

    Dequeue first k item form queue & push to stack
    Put oit agaim (queue) from stack to queue
    Deque (size - k) in same element

    TC = O(N+K)
    SC = O(K)
 */

void solve(queue <int> &Queue  , int k ){
    if (k >= Queue.size()) return;
    stack <int> Stack;
    for (int i = 0; i < k; i++ ){
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()){
        Queue.push(Stack.top());
        Stack.pop(); // it came in reverse order
    }
    for (int i = 0; i < Queue.size() - k; i++){ // now time to arrange it
        Queue.push(Queue.front());
        Queue.pop();
    }

}


int main() {
    queue<int> Queue;
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue.push(5);

    int k = 3;

    cout << "Original Queue: ";
    queue<int> tempQueue = Queue; // Temporary queue to display original elements
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    solve(Queue, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
    cout << endl;

    return 0;
}