/* To rotate array there are usually two methods 
(i)Using temp array 
(ii)Using reverser algo  
2nd logic =>
Let arr = { 8 , 16 , 3 , 10 , 25 , 7 , 14 , 22 , 19 , 33 , 11 , 45 , 2 , 6 , 31 , 17 , 9 , 4 , 27 , 13 } and k  = 3 
so     reverse(arr, 0,size-k-1) => { 9 , 17 , 31 , 6 , 2 , 45 , 11 , 33 , 19 , 22 , 14 , 7 , 25 , 10 , 3 , 16 , 8 , 4 , 27 , 13 }
because 0th index is 8 and size - k - 1 => 20 - 3 - 1 => 16 , 16th index is 9
next      reverse(arr, size-k, size-1); => size - k=> 17th index is 4 and size - 1 index is 19th index is 13 => { 9 , 17 , 31 , 6 , 2 , 45 , 11 , 33 , 19 , 22 , 14 , 7 , 25 , 10 , 3 , 16 , 8 , 13 , 27 , 4 }
now reversing all gives { 4 , 27 , 13 , 8 , 16 , 3 , 10 , 25 , 7 , 14 , 22 , 19 , 33 , 11 , 45 , 2 , 6 , 31 , 17 , 9 }


let now undertood mathmatical prove by this work
let arr = {0,1,2..k-1,k,k+1...n-2,n-1} == {0,1,2..,n-k-2,n-k-1,n-k,n-k+1,...n-2,n-1}
reverse(arr, 0,n-k-1) => {n-k-1,n-k-2..2,1,0,n-k,n-k+1,...n-2,n-1}
reverse(arr, n-k, n-1) => {n-k-1,n-k-2..2,1,0,n-1,n-2,...n-k+1,n-k}
reverse all => {n-k,n-k+1..n-2,n-1,0,1,2...n-k-2,n-k-1}





*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void display(vector<int> &arr){
    cout << endl << "{ ";
    int size = arr.size();
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " }";
}

void by_method_1(vector<int> &arr , int k){
    vector<int> temp(k,0);
    for (int i = 0 ; i < k ; i++) temp[i] = arr[arr.size()-k+i] ; 
    for (int i = arr.size() - 1 ; i >= k ; i--) arr[i] =  arr[i-k];
    for (int i = 0; i < k ; i++) arr[i] = temp[i];

}

void reverse(vector<int> &arr , int start , int end){
    while (start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void by_method_2(vector<int> &arr, int k){
    int size = arr.size();
    reverse(arr, 0,size-k-1);
    // display(arr);
    reverse(arr, size-k, size-1);
    // display(arr);
    reverse(arr,0,size-1);
}




int main(){
    cout << endl;

    vector<int> arr = {8, 16, 3, 10, 25, 7, 14, 22, 19, 33, 11, 45, 2, 6, 31, 17, 9, 4, 27, 13} ;
    display(arr);
    int k ;
    cout << endl << "How much you want to rotate the array? " ; cin >> k ; 
    if (k<1) {
        cout << "ERROR : Invalid input , number must be positive" ;
        return 0;
    }
    k %=  arr.size();

    by_method_1(arr,k);

    display(arr);
   

    
    
    
    cout << endl;
    return 0;
}
