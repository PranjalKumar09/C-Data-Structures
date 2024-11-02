#include <bits/stdc++.h>
using namespace std;

/* 
Heapify Algo Min Heap
=======================
*/

void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[smallest] > arr[left]) smallest = left;
    if (right < n && arr[smallest] > arr[right]) smallest = right;

    if (smallest != i) { // check if update
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
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


