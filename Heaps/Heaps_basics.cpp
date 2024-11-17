#include <bits/stdc++.h>
using namespace std;

/* 
    HEAPS
=============
    
    it is a CBT that comes with heap order property 
    CBT -> if right empty then it will ok but not left.

    property of heap in which child are 
                                        Max heap -> smaller than parent
                                        Min heap -> longer than parent
    Max heap -> 
         6
       /   \
      5     3
     / \   /
    4   2 1

    Min heap -> 
         1
       /   \
      3     2
     / \   /
    4   6 5


    Insertion (with array)
    ------------------------
        (Max heap )

        Left Child  = 2 * i
        Right Child = 2 * i + 1
        parent = (i/2)

        Size + 1

        | x | 60 | 50 | 40 | 30 | 20 

        1) Insert at End
        2) Take at correct Pos
            Check by parent   {Top to correct Pos}
                If correct continue 
                else swap by parent    
        
    
    Deletion->root node
    --------------------
        1) Swap fist node withnpast node or put O(1)
        2) Remove last node O(1)
        3) Propagate root node to correct pos * compare to children    

    0 based Indexing 
        Left -> 2*i + 1
        Right-> 2*i + 2

    1 based Indexing 
        Left -> 2*i 
        Right-> 2*i + 1
*/

class Heap{
public:
    int arr[100];
    int size = 0;

    void insert(int val){
        size += 1;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return ;
        }
    }
    void deleteRoot(){
        if (!size){
            cout << "Heap is Empty" << endl;
            return ;
        }
        arr[1] = arr[size];
        size -= 1;
        int index = 1;
        while (index < size){
            int left = 2*index;
            int right = 2*index + 1;
            int max = index;
            if(left <= size && arr[left] > arr[max])
                max = left;
            
            else if(right <= size && arr[right] > arr[max])
                max = right;
            
            else
                break;
            
            swap(arr[index], arr[max]);
            index = max;
        }
    }
    Heap(){
        arr[0] = -1;
        size = 0;
    }
};

int main() {
    Heap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(40);
    heap.insert(50);

    cout << "Heap elements: ";
    for(int i = 1; i <= heap.size; i++)
        cout << heap.arr[i] << " ";
    cout << endl;

    heap.deleteRoot();

    cout << "Heap elements after deleting root: ";
    for(int i = 1; i <= heap.size; i++)
        cout << heap.arr[i] << " ";
    cout << endl;

    return 0;
}
