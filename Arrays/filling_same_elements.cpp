/*
filling same elements in array
1) by intiliaing it
2) using designated initliazers (not work, it work only gcc compiler type)
3) fill in


*/
#include<iostream>
using namespace std;

void display(int arr[], int size){
    cout << endl << "[ ";
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " ]";
}


int main(){

    int arr1[5] = {7,7,7,7,7};
    display(arr1, 5);

    // int arr2[5] = {[0 . . . 4] = 7};
    // display(arr2,5);
    int arr3[5];
    fill_n(arr3,5,8);
    display(arr3,5);

    return 0 ;
}