#include<iostream>

using namespace std;

int BinarySearchRecursive(int arr[] , int target , int left , int right){
    if (right < left) return -1;
    int mid = left + (right-left)/2;
    if (arr[mid] == target) return mid;
    if (target > arr[mid]) return BinarySearchRecursive(arr , target ,mid + 1 ,right);
    return BinarySearchRecursive(arr , target ,left,mid - 1);


}

int BinarySearch(int arr[] , int size,int target){
    int low = 0 , high = size - 1 ;
    while (low <= high){
        int mid = low+ (high-low)/2;
        if (arr[mid] == target) return mid;
        target > arr[mid] ?  low = mid+1:high = mid-1;
        }
    return -1;
}

int main(){

    cout << "Enter the number to search in array: ";

    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40} , target;

    cin >> target ; cout << endl; 

    int size = sizeof(arr) / sizeof(int)  ; 


    // Method 1 : Non recursive preffered

    // int index = BinarySearch(arr, size , target);


    // Method 2 : Recursive preffered

    int index = BinarySearchRecursive(arr, target , 0 , size - 1);


    //Output show 

    index != -1 ? cout << "The number " << target << " is found at index " << index << " . " : cout << "Number not found ";

    cout << endl ; 




    





    

    return 0;
}