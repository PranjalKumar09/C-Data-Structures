#include<iostream>
#include<vector>
using namespace std;



void Display(int arr[], int size){
    cout << "[ "; 
    for (int i = 0 ; i < size -1 ; i++){
        cout << arr[i] << " , ";
    }
    cout << arr[size-1] << " ] " << endl; 
}
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


int main(){
    int arr[] = {0,1,2,0,2,2,1,1};
    int size = sizeof(arr)/sizeof(int);

    // Method 1 -> by sorting 0,1,2 

    int result_arr[] = {0,1,2,0,2,2,1,1};
    MergeSort(result_arr , 0 , size-1);
    Display(result_arr , size);

    //Method 2 variable and count each
    int result_arr2[] = {0,1,2,0,2,2,1,1} , count0 = 0,count1 = 0 , count2 = 0 ; 

    for (int i = 0; i < size ; i++){
        if (arr[i] == 0 ) count0++;
        else if (arr[i] == 1 ) count1++;
        else if (arr[i] == 2 ) count2++ ;
    }
    int index = 0;
    while( count0){
        count0--;
        result_arr2[index++] = 0;        
    }
    while( count1){
        count1--;
        result_arr2[index++] = 1;        
    }
    while( count2){
        count2--;
        result_arr2[index++] = 2;        
    }

    Display(result_arr2,size);



    // Method 3 (3 poniters)
    int result_arr3[] =  {0,1,2,0,2,2,1,1}  , count_loop = 0;
    int low = 0, mid  = 0 , high = size-1;
    while(mid<=high){ //perferred use if everytime not if else
        if (result_arr3[mid] == 0) swap(result_arr3[low++] , result_arr3[mid++]);
        if (result_arr3[mid] == 1){ mid++; result_arr3[mid-1] == 1;}
        if (result_arr3[mid] == 2) {
            swap(result_arr3[mid++] , result_arr3[high--]);}
        count_loop++;
    }   
    Display(result_arr3 ,  8);
    cout << "The loop runned for " << count_loop;




    return 0;
}