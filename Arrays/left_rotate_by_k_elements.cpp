/* 

Note:

(1)in below loop it is mistake 
    for (int i = 0; i < k ; i++) arr[arr.size()-k-1+i] = temp[i];
    Correct loop is     for (int i = 0; i < k ; i++) arr[arr.size()-k+i] = temp[i];
(2) Notice reverse 
void by_method_2(vector<int> &arr, int k){
    int size = arr.size();
    reverse(arr, 0,k-1); //line 1
    reverse(arr, k, size-1); //line 2
    reverse(arr,0,size-1); //line 3
}
in this remember *last  step (3)will same in left and right
*you can put line 1 & 2 in any order

Method 1 -> TC = O(2N)    SC = O(K)
Method 2 -> TC = O(2N)    SC = O(1)
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
    for (int i = 0 ; i < k ; i++) temp[i] = arr[i] ; 
    for (int i = 0 ; i < arr.size()-k ; i++) arr[i] =  arr[i+k]; //    for (int i = 0 ; i <= n-k-1 ; i++) arr[i] =  arr[i+k];   
    for (int i = 0; i < k ; i++) arr[arr.size()-k+i] = temp[i];

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
    reverse(arr, 0,k-1);
    reverse(arr, k, size-1);
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

    by_method_2(arr,k);

    display(arr);
   

    
    
    
    cout << endl;
    return 0;
}
