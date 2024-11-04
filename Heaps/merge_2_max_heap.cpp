#include <bits/stdc++.h>
using namespace std;

/* 
Merge 2 Binary Max-Heap
=======================

    i/p : mh1 , mh2 

*/
class Node {
public:
    int value;
    Node* left, *right;
    Node(int data) {
        this->value = data;
        this->left = this->right = NULL;
    }
};

priority_queue<int> solve(priority_queue<int> pq1,priority_queue<int> pq2){
    priority_queue<int> pq3;
    while(!pq1.empty() ||!pq2.empty()){
        if(!pq2.empty()){
            pq3.push(pq2.top());
            pq2.pop();
        }
        else if(!pq1.empty()){
            pq3.push(pq1.top());
            pq1.pop();
        }
    }
    return pq3;
}

int main(){
    priority_queue<int> pq1, pq2;
    
    // Insert elements into pq1
    pq1.push(1);
    pq1.push(3);
    pq1.push(5);
    
    // Insert elements into pq2
    pq2.push(2);
    pq2.push(4);
    pq2.push(6);

    // Merge pq1 and pq2
    priority_queue<int> merged_pq = solve(pq1, pq2);

    // Print the merged priority queue
    cout << "Merged Priority Queue: ";
    while (!merged_pq.empty()) {
        cout << merged_pq.top() << " ";
        merged_pq.pop();
    }
    cout << endl;

    return 0;
}


 
// Th

