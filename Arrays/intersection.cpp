#include <iostream>
using namespace std;

/*
 


*/
int main(){
    int arr1[9] = {1,2,3,3,4,5,6,7,8};
    int arr2[9] = {7,9,10,12,13,14,15,16,17};
    int i = 0 , j = 0;
    while (i < sizeof(arr1)/sizeof(int) && j < sizeof(arr2)/sizeof(int)  ){
        if (arr1[i] < arr2[j]) i++;
        else if (arr1[i] == arr2[j]) {
            cout << arr1[i]<<endl;
            i++; j++;   }
        else j++;   }
    
    

    return 0 ;
}