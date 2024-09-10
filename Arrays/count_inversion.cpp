/* 
Remember this inversion_count += mid-i+1; 
Brute Force logic: TC =  O(N^2)  ,  SC = O(1) 
Merge sort : TC =  O(N log N)  ,  SC = O(N)
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int brute_force_count_inversion( vector<int> &arr){
    int count=0;
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}

int merge(vector<int> &arr ,int start, int mid , int end){
    int i=start,j=mid+1;

    vector<int> temp;
    int inversion_count = 0;
    while(i<= mid && j <= end){
        if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else {temp.push_back(arr[j++]);
        inversion_count += mid-i+1;}
    }
    // cout << " swap: " << swap << endl;
    while(i<= mid ) temp.push_back(arr[i++]);
    while(j <= end) temp.push_back(arr[j++]);
    for (int i=start; i<= end ; i++) arr[i] = temp[i-start];
    return inversion_count;

}

int merge_sort_count_inversion(vector<int> &arr ,int start , int end){
    if(start>=end) return 0;
    int count = 0;
    int mid = start+(end-start)/2;
    count += merge_sort_count_inversion(arr,start,mid);
    count += merge_sort_count_inversion(arr,mid+1,end);
    count += merge(arr,start,mid,end);
    return count;
}

int main(){
    cout << endl;
    
    vector<int> array =  { 5, 4, 3, 2, 1} ;
    // cout << "The number of inversion is " << brute_force_count_inversion(array);
    cout << "The number of inversion is " << merge_sort_count_inversion(array, 0 , array.size() - 1);
    cout << endl;
    return 0;
}