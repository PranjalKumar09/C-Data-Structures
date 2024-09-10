/*  kth_largest = (size - k + 1)th smallest
 Kth_Smallest = (size - k + 1)th largest 

 3rd Method

 partition function:
This function is responsible for partitioning a portion of the array arr between indices left and right. It chooses the leftmost element arr[left] as the pivot and rearranges the elements in such a way that all elements smaller than the pivot are on the left side, and all elements greater than the pivot are on the right side.

kth_largest function:
This function utilizes the partition function to find the kth largest element in the array arr .

The kth_largest function repeatedly calls partition until it finds the index (idx) where the kth largest element should be. If idx is equal to k - 1, it means the kth largest element is found, and the function returns that element. If idx is less than k - 1, the algorithm continues the search in the right subarray, otherwise in the left subarray.
 */

#include <iostream>
#include<vector>
#include<set>
using namespace std;

void Display(int arr[], int size){
    cout << "[ "; 
    for (int i = 0 ; i < size -1 ; i++){
        cout << arr[i] << " , ";
    }
    cout << arr[size-1] << " ] " << endl; 
}
void Merge(int arr[] , int start , int mid ,int end){
    int left = start , right = mid+1;
    vector<int> temp;
    while(left <=  mid && right<= end){
        if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);}
    while(left <=  mid) temp.push_back(arr[left++]);
    while(right<= end) temp.push_back(arr[right++]);
  
    for(int index = start ; index <= end ; index++)
        arr[index] = temp[index-start];
}

void MergeSort(int arr[] , int start , int end){
    if (start >= end) return;
    int mid = start + (end-start)/2;
    MergeSort(arr ,start ,mid);
    MergeSort(arr ,mid+1 ,end);
    Merge(arr,start,mid,end);
}

void DisplaySmallestLargest(int k , int smallest , int largest){
    cout << k <<"th Maximum element is " << largest << endl << k<<"th Minimum element is " << smallest << endl;
}

int partition(int arr[], int left, int right){
    int pivot = arr[left];
    int l = left+1, r = right;
    while(l<=r){
        if (arr[l] < pivot && arr[r] > pivot) swap(arr[l++] , arr[r--]);
        if (arr[l] >= pivot ) l++;
        if (arr[r] <= pivot ) r--;    }
    swap(arr[left] , arr[r]); // in above loop no postioning/swapping of pivot 
    return r;}


int kth_largest ( int arr[] ,int size, int k ){
    int left = 0 , right = size - 1, kth;
    while(1){
        int idx = partition(arr,left,right); //This index is significant because it represents the correct position of the pivot in the sorted array.
        if (idx == k-1){
            kth = arr[idx];
            break;}
        if (idx < k-1) left = idx+1;
        else right = idx-1;}
    return kth;}

int main(){
    int arr[] = {8, 16, 3, 10, 25, 7, 14, 22, 19, 33, 11, 45, 2, 6, 31, 17, 9, 4, 27, 13};
    int size = sizeof(arr)/sizeof(int) , k = 4;
    
    // method 1 by using sorting 
    int result_arr1[] = {8, 16, 3, 10, 25, 7, 14, 22, 19, 33, 11, 45, 2, 6, 31, 17, 9, 4, 27, 13};
    MergeSort(result_arr1, 0 , size -1);

    DisplaySmallestLargest(k , result_arr1[k-1] , result_arr1[size-k]);

    Display(result_arr1 , size);

    //  Method 2: Set data structure

    set<int> temp = {8, 16, 3, 10, 25, 7, 14, 22, 19, 33, 11, 45, 2, 6, 31, 17, 9, 4, 27, 13};

    
    set<int>::iterator it = temp.begin();
    advance(it, temp.size() - k);
    int kthLargest = *it;

    
   
    it = temp.begin();
    advance(it, k - 1);
    int kthSmallest = *it;

    DisplaySmallestLargest(k,  kthSmallest , kthLargest);
    


    // method 3 by quickselect algorithm
    int arr2[] = {8, 16, 3, 10, 25, 7, 14, 22, 19, 33, 11, 45, 2, 6, 31, 17, 9, 4, 27, 13};

    DisplaySmallestLargest(k , kth_largest(arr2,size,size - k + 1) ,kth_largest(arr2,size,k)) ; 



    return 0;
}