/* First and last occurence of element in array 
Note : Terneary Opraotor can,t be applied in multiple if else statement like here */

#include<iostream>

using namespace std;

int Last_Occurence(int arr[], int target, int size ){
    int left = 0 , right = size-1;
    int ans = -1;
    while(left <= right){
         int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            ans = mid;
            left = mid + 1;  // Update left only when arr[mid] == target
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans; 
}



int First_Occurence(int arr[], int target, int size ){
    int left = 0 , right = size-1;
    int ans = -1;
    while(left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            ans = mid;
            right = mid - 1;  // Update right only when arr[mid] == target
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans; 
}

int main(){

    cout << "Enter the number to search in array: ";
    int arr[] = {-10, -5, 0, 2, 2, 2, 5, 8, 10, 15} , target;
    int size = sizeof(arr) / sizeof(int)  ; 

    cin >> target ; cout << endl; 

    int start = First_Occurence(arr, target ,size) , last = Last_Occurence(arr, target ,size) ; 
    start == -1 ? cout << "Number not exist in the array ": cout << "First occurence is " << start << " Last occurence is " << last ; 

    cout << endl;
    return 0;
}
