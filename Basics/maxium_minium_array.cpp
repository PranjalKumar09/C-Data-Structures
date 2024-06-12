#include<iostream>
#include<vector>

using namespace std;

/*
SITES SOLUTIONS
https://www.geeksforgeeks.org/problems/max-min/1
int findSum(int A[], int N)
    {
    	int smallest =  A[0] , largest = A[0];
  
        for (int i = 1 ; i < N ; i++){
            if (smallest > A[i]) smallest = A[i];
            if (largest < A[i]) largest = A[i];}
    
    return smallest + largest;
}

*/


void merge( vector<int> &arr , int low , int mid , int high){
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left  <= mid && right <= high){
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else    temp.push_back(arr[right++]);
    }
    while (left  <= mid)    
        temp.push_back(arr[left++]);
    
    while (right <= high)
     temp.push_back(arr[right++]);
    
    for (int i =low ; i<= high; i ++)
        arr[i] = temp[i-low];
}

void MergeSort(vector<int> &arr , int low, int high){
    if (low>=high) return;
    int mid = (low+high)/2;
    MergeSort(arr , low , mid);
    MergeSort(arr , mid + 1 , high);
    merge(arr,low,mid,high);
}


void method1(vector<int> &arr){

    MergeSort(arr , 0 , arr.size() - 1);
    cout << "Smallest - >" << arr[0] << endl;
    cout << "Largest - >" << arr[arr.size() - 1];

}

int main(){
    vector<int> arr = {3,4,2,1,76,5,4,43};
    // method1(arr);

    int smallest =  arr[0] , largest = arr[0];
    //method 2
    for (int i = 1 ; i < arr.size() ; i++){
        if (smallest > arr[i]) smallest = arr[i];
        if (smallest < arr[i]) largest = arr[i];}
    cout << "Smallest - >" << smallest << endl;
    cout << "Largest - >" << largest;

    return 0 ;
}