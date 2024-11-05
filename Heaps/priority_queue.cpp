#include <bits/stdc++.h>
using namespace std;
/* 
Priority Queue
==============

    all operation of queue works

    max queue can be normal announced 

    min pq -> priority_queue<int, vector<int>, greater<int>>  

    pq.emplace(<int>) // insert element in pq but differebnce is that it save unnecessary copy of it

    Method      TC          SC
---------------------------------
    empty       O(1)        O(1)
    size        O(1)        O(1)
    top         O(1)        O(1)
    push        O(log n)    O(1)
    pop         O(log n)    O(1)
    swap        O(log n)    O(1)
    emplace     O(log n)    O(1)
    

 */

int main() {
    // Creating a priority queue of integers
    priority_queue<int> pq;

    // Inserting elements into the priority queue
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // Printing the top element of the priority queue
    cout << "Top element: " << pq.top() << endl;

    // Removing the top element
    pq.pop();

    // Printing the top element after removal
    cout << "Top element after removal: " << pq.top() << endl;

    // Printing the size of the priority queue
    cout << "Size of priority queue: " << pq.size() << endl;



    // Creating a min-heap using priority_queue with greater
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Inserting elements into the min-heap
    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(20);

    // Printing the top element of the min-heap
    cout << "Top element: " << minHeap.top() << endl;

    // Removing the top element
    minHeap.pop();

    // Printing the top element after removal
    cout << "Top element after removal: " << minHeap.top() << endl;

    // Printing the size of the min-heap
    cout << "Size of min-heap: " << minHeap.size() << endl;



    return 0;
}
