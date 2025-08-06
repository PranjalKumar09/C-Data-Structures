/*
Quick sort not stable sorting algorithm in its typical implementation
Quick Sort is in place swapping technique not stable 


Advantage of Quick Sort

* Divide & conquer algorithm that makes easier to solve problems
* Efficient on large data sets 
* Low overhead as it only requires small amount of memory to function

Disadvantage of Quick Sort

* Worst Case TC = o(N2) when pivot choosen poorly
* Not good choice for small data sets

* Not stable sort meaning that if two element have same key their relative order will not be preserved in sorted output in case of quick sort, because here we preserved in sorted output in case of quick sort, because here we swapping elements according to pivot postion (without considering their original position)

*/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector<int> &array) {
    for (int num : array) 
        cout << num << " ";
    
    cout << endl;
}



int partition(vector<int> &arr, int low, int high) {
    // Choose  pivot (usually first element in array)
    // for that reason we will do upcoming loop in low + 1
    int pivot = arr[low];
    // Initialize two pointers, i and j

    // it avoided high-1 because for partition list must be devided
    int i = low;
    int j = high;

    // Main partitioning loop
    while (i < j) {
        // Increment i until an element greater than pivot is found
        while (arr[i] <= pivot && i <= high - 1) 
            i++;
        // Decrement j until an element less than or equal to  pivot is found
        while (arr[j] > pivot && j >= low + 1) 
            j--;

        // Swap the elements at i and j if i is still less than j
        if (i < j) 
            swap(arr[i], arr[j]);
    }


    // Swap the pivot with the element at index j, placing the pivot in its final sorted position
    swap(arr[low], arr[j]); // actual changing of pivot

    // Print the current state of the array after the swap (for debugging)
    // cout << "arr[j] " << arr[j] << " | "; 
    // display(arr);  // Assuming you have a display function to print the array

    // Return the final position of the pivot in the sorted array
    return j;
}


void qs(vector<int> &array , int low, int high){
    if(low<high){
        int pindex = partition(array , low , high);
        qs(array,low,pindex-1);
        qs(array,pindex+1,high);
        
    }
}
vector<int> quicksort(vector<int> &array ){
    qs(array , 0 , array.size()-1);
    return array;
}

int main() {

    vector<int> array = {10, 5, 2, 3, 4, 6, 7, 8, 9};
    display(array);
    array = quicksort(array);
    display(array);


    return 0;
}