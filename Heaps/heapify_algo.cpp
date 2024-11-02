#include <bits/stdc++.h>
using namespace std;

/* 
Heapify Algo
============
    
    Correct node of given index
    Convert into heap

    In CBT 
        leaf nodes 
            (n/2 + 1) -> nth index

    leaf node will always -> opposite bcz checking bottom tour

    ignore leaf nodes

    TC = O(log N)

*/

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left]) largest = left;
    if (right < n && arr[largest] < arr[right]) largest = right;

    if (largest != i) { // check if update
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Heapify the array
    for (int i = n / 2 - 1; i >= 0; --i) 
        heapify(arr, n, i); // it will traverse throughout heap(max)

    cout << "Array after heapify: ";
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " ";
    
    cout << endl;

    return 0;
}


