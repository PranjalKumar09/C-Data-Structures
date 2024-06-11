#include <iostream>
using namespace std;

// 2 approaches 1-> 2 pointer approach 2-> reverse by recursion

void display(int arr[], int size){
    cout << endl << "[ ";
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " ]";
}

void reverse_by_swap(int arr[], int size){
    for (int i = 0 ; i < (size)/2 ; i++){
        swap(arr[i], arr[size - i -1]);
    } 
}

void reverse_by_recursion(int arr[] , int start , int end){
    if (start >= end)
        return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp ; 
    return reverse_by_recursion(arr, ++start , --end);

}

int main(){
    int arr[7] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(int);
    display(arr , size);
    reverse_by_swap(arr,size);
    display(arr , size);
    reverse_by_recursion(arr,0,size-1);
    display(arr , size);


    

    return 0;
}