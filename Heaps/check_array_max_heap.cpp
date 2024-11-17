#include <bits/stdc++.h>
using namespace std;

/*  
Check whether array is Max Heap
===============================


*/

bool solve(vector<int>& array){
    int bound = (array.size())/2;
    for(int i=0;i<bound;i++){
        if(array[i]<array[2*i+1] || 2*i+2 < array.size() && array[i]<array[2*i+2]  )
            return false;
    }
    return true;
}

int main(){    
    
    
    // Test case 1: Valid binary tree (parent >= children)
    vector<int> arr1 = {90, 15, 10, 7, 12, 2} ;
    cout << "Result for arr1: " << (solve(arr1) ? "true" : "false") << endl;

    // Test case 2: Invalid binary tree (parent < children)
    vector<int> arr2 = {3, 7, 5, 0, 2, 4, 6};
    cout << "Result for arr2: " << (solve(arr2) ? "true" : "false") << endl;

    // Test case 3: Edge case with only one element
    vector<int> arr3 = {5};
    cout << "Result for arr3: " << (solve(arr3) ? "true" : "false") << endl;

    return 0;
}
