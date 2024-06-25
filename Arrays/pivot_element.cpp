/* pivot can any element either lowest or maximum 
so here let pivot will be
*/
#include<iostream>

using namespace std;

int pivot(int arr[], int size) {
    int left = 0 , right = size-1;
    while(left < right) {
        int mid = left + (right - left)/2;
        arr[mid] >= arr[0] ? left = mid + 1 : right = mid;}
    return left;

}

void display_output(int arr[], int size ){
    cout << "The pivot(index) in array is " << pivot(arr, size) << " and element is " << arr[pivot(arr, size)] <<endl;
}

int main(){
    cout << endl;
    int arr[] = {12,13,14,1,2,3,4,5,6,7,8,9,10,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    display_output(arr , size);

    
    cout << endl;
    return 0;
}