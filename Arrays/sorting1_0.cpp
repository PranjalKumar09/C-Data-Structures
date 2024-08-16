#include <iostream>
#include <vector>
using namespace std;
void Merge(int arr[] , int start , int mid , int end){
    int left  = start, right = mid + 1;
    vector <int> temp;
    while (left <= mid && right <= end){
        if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);   }
    while (left <= mid )
        temp.push_back(arr[left++]);  
    while (right <= end) temp.push_back(arr[right++]);  
    for (int i = start;  i <= end ; i++ ){
        arr[i] = temp[i-start];
    }
    
}
void MergeSort(int arr[],int start , int end ){
    if (start>=end) return;
    int mid = start + (end-start)/2;
    MergeSort(arr, start , mid);
    MergeSort(arr,  mid + 1 ,end);
    Merge(arr, start , mid , end);
}


void display(int arr[] , int size){
    cout << "[ ";
    for(int i  =0 ; i < size-1; i++){
        cout << arr[i] << " , ";
    }
    cout << arr[size-1] <<" ]" << endl;
}

int main(){
    int arr[10] = {0,0,0,1,1,1,0,1,1,0};
    int size = sizeof(arr)/sizeof(int); 
    display(arr,size);

    // method 1 count 0 and 1 then transverse it 
    int count0 = 0, count1=0;
    for(int i = 0; i< size ; i++){
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
    }
    int result_arr[count0+count1];
    int i = 0;
    while (count0){
        result_arr[i] = 0;
        i++; count0--;
    }
    while (count1){
        result_arr[i] = 1;
        i++; count1--;
    }

    display(result_arr,size);


    //method 2 by sorting
    int result_arr2[size] = {0,0,0,1,1,1,0,1,1,0};
    
    MergeSort(result_arr2, 0, size-1);
    display(result_arr2,size);


    // method 3 by  2-pointer method
    int result_arr3[size] = {0,0,0,1,1,1,0,1,1,0};
    int left = 0 , right  = size-1;
    while(left < right){
        if (result_arr3[left] == 1 && result_arr3[right] == 0)
            swap(result_arr3[left++],result_arr3[right--]);        
        else if (result_arr3[left] ==  0 && result_arr3[right] == 1)
            {left++;right--;}
        else if (result_arr3[left] ==  1 && result_arr3[right] == 1)
            right--;
        else left++;
    }
    display(result_arr3, size);






    return 0;
}