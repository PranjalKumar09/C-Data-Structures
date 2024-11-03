    #include <bits/stdc++.h>
    using namespace std;

    /* 
    Kth Largest / Smallest by Heap
    ===============================

        Max Heap -> Kth Largest
        Min Heap -> Kth Smallest

        Just remove top k - 1

        i/p : array or vector<int> , int k

    */

int KthSmallest(vector<int> &arr , int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < arr.size(); i++) 
        minHeap.push(arr[i]);
    

    for (int i = 0; i < k - 1; i++) 
        minHeap.pop();
    

    return minHeap.top();
}

int KthLargest(vector<int> &arr , int k){
    priority_queue<int> maxHeap;

    for (int i = 0; i < arr.size(); i++) 
        maxHeap.push(arr[i]);
    

    for (int i = 0; i < k - 1; i++) 
        maxHeap.pop();
    

    return maxHeap.top();
}

  
int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5}; // Example array

    int k = 3; // Example value of k

    cout << k << " Smallest: " << KthSmallest(arr, k) << endl;
    cout << k << " Largest: " << KthLargest(arr, k) << endl;

    return 0;
}


