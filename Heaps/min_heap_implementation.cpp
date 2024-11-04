#include <bits/stdc++.h>
using namespace std;

/* 
Min Heap Implementation 
=======================
(0 based indexing)



*/

class Heap{
public:
    int *arr;
    int size = 0;
    int capacity; // max size

    Heap(int capacity){
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }
    
    int parent(int i){ return (i-1)/2;}
    int left(int i){ return 2*i + 1;}
    int right(int i){ return 2*i + 2;}

    void insert(int val){
        if (size >= capacity){
            cout << "Heap overflow";
            return ;
        }
        arr[size]=val;
        int k = size;
        size += 1;

        while(k && arr[parent(k)] > arr[k]){
            swap(arr[k], arr[parent(k)]);
            k = parent(k);
        }
    }
    void deleteRoot(){
        if (size <= 0){
            cout << "Heap underflow";
            return ;
        }
        swap(arr[0], arr[size-1]);
        size -= 1;
        heapify(0);
    }
    void heapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);
        if (l < size && arr[l] < arr[smallest]) smallest = l;
        if (r < size && arr[r] < arr[smallest]) smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }
    int getMini(){
        return arr[0];
    }

};

int main() {
    Heap minHeap(10);

    minHeap.insert(30);
    minHeap.insert(10);
    minHeap.insert(20);

    cout << "Minimum element: " << minHeap.getMini() << endl;

    minHeap.deleteRoot();

    cout << "Minimum element after deletion: " << minHeap.getMini() << endl;

    return 0;
}

