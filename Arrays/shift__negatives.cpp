
/* 
Some important points
conation is (left < right) NOT left <= right so remember.
Also no mid  make in this
IF If left value is less than 0 then increase left 
ELSE else check if right one greater than 0 then decrease right
ELSE IF if both fails then only one thing possible left one is postive and right one is negative then swap them  */
#include<iostream>

using namespace std;


void display(int arr[], int size){
    cout << endl << "{ ";
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " }";
}

void Shift_All_Negative_Number_left(int arr[] , int size){
    int left = 0 , right = size - 1 ; 
    while(left < right) { 
        if (arr[left] < 0 ) left++ ;
        else if (arr[right] > 0)right--;
        // now only one condion remain if left is +ve & right is -ve 

        else swap(arr[left] , arr[right]);

    }
}

int main(){
    int arr[] ={7, -5, 10, -2, 8, -15, 3, 0, -9, 12, -6, 4, -11, 1, -8};
    int size = sizeof(arr) / sizeof(int)  ; 

    display(arr,size) ; 

    Shift_All_Negative_Number_left(arr, size);

    display(arr,size) ; 

    
    cout << endl;
    return 0;
}
