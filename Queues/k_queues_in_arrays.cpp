#include <bits/stdc++.h>
using namespace std;

/* 
K QUEUES IN ARRAY

    Method 1: 
        n/k parts = but space not optimized



    Method 2:
        
        front[]:  size k store indexes of front elements
        rear[] :  size k store indexes of rear elements
        next[] :  size n  & store indexes of next item for all items
        free   :  store beginning of free list
 */

class KQueue {
    int *arr , *front , *rear , *next;
    int n, k , free;

public:
    KQueue(int n, int k){
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        free = 0;
        for(int i=0; i<n; i++)  next[i] = i+1;
        next[n-1] = -1;
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }
    }

    void enqueue(int item, int qn){
        if (isFull()){
            cout << "Queue Overflow" ;
            return;
        }
        int i = free;
        free = next[i];
        if (isEmpty(qn)) // because front = rear = -1
            front[qn] = i; // updating first element

        else next[rear[qn]] = item;// make sure if other than first connect index with next
        //         ------------->
        // _Q1_ _Q1_ -q2- -q2- _Q1_ -q2- 
        //                  ---------->

        next[i]=-1;
        rear[qn] = i;
        arr[i] = item;
    }
    bool isFull(){
        return free == -1;
    }
    bool isEmpty(int qn){
        return front[qn] == -1;
    }
    int dequeue(int qn){
        if (isEmpty(qn)){
            cout << "Queue Underflow" ;
            return -1;
        }
        int i = front[qn]; // firstly find front index
        
        front[qn] = next[i]; // update front index to next space
        // ab suruwat wale ko update karenge

        next[i] = free; // connecting next to free space
        free = i; // set free 
        return arr[i];
    }  

    ~KQueue() {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main() {
    int n = 10, k = 3;
    KQueue kq(n, k);

    kq.enqueue(15, 0);
    kq.enqueue(45, 0);

    kq.enqueue(17, 1);
    kq.enqueue(49, 1);
    kq.enqueue(39, 1);

    kq.enqueue(11, 2);
    kq.enqueue(9, 2);
    kq.enqueue(7, 2);

    cout << "Dequeued from queue 0: " << kq.dequeue(0) << endl;
    cout << "Dequeued from queue 1: " << kq.dequeue(1) << endl;
    cout << "Dequeued from queue 2: " << kq.dequeue(2) << endl;

    return 0;
}