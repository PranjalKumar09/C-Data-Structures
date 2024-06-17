#include<iostream>

using namespace std;

int Mountain_Element_Array_Linear_Search(int arr[], int size){
    for (int i = 1; i < size; i ++){
        if (arr[i] > arr[i + 1] && arr[i] < arr[i-1])
            return i;
    }
    return -1;
}
int Mountain_Element_Array_Binary_Search(int arr[], int size){
    int left = 1 , right = size -2;
    while (left < right    ){  
        int mid = left + (right - left) / 2;
        if (arr[mid + 1 ] < arr[mid] && arr[mid] > arr[mid-1]) return mid;
        arr[mid] < arr[mid+1] ? left = mid +1: right = mid;}
    return -1;
}

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,7,6,5,4,3,2,1};

    int size = sizeof(arr) / sizeof(int)  ; 

    // Method 1 

    int index = Mountain_Element_Array_Binary_Search(arr, size);

    // Method 2 

    // int index = Mountain_Element_Array_Linear_Search(arr, size);

    if (index == -1) return -1;


    cout << "index is " << index << " and value is " << arr[index] << endl; 
    
    cout << endl;

    return 0;
}





