/* 
1) Brute Force: Sort and  return 1 & n-2 index
2) Find largest and smllest then element just smaller then largest same in largest just larger then smallest.
3) Optimized Solution: 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void DisplayOutput( int smallest , int largest){
    cout <<"2nd Maximum element is " << largest << endl <<"2nd Minimum element is " << smallest << endl;
}

//Merhod 1 

void display(vector<int> &arr){
    cout << endl << "{ ";
    int size = arr.size();
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " }";
}
void merge(vector<int> &arr , int start , int end, int mid){
    int s_start = start, e_start = mid+1;
    vector<int> temp;
    while (s_start <= mid && e_start <= end)
    {
        if (s_start < e_start) temp.push_back(arr[s_start++]);
        else temp.push_back(arr[e_start++]);
    }
    while(s_start <= mid)temp.push_back(arr[s_start++]);
    while(e_start <= end )temp.push_back(arr[e_start++]);
    for(int i = start; i <= end; i++)
        arr[i] = temp[i-start];   
}

void MergeSort(vector<int> &arr, int start, int end){
    if (start >= end) return;
    int mid = start +(end - start)/2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);
    merge(arr, start, end, mid);

}

void Method1_BruteForce(vector<int> arr){
    MergeSort(arr, 0, arr.size()-1);
    // display(arr);
    DisplayOutput(arr[1] , arr[arr.size()-2]);
}

//Method2

void Method2(vector<int> &arr){
    int mini  = 1e8 , maxi = -1e8 , minimum2 = 1e8 , maximum2 = -1e8;
    for (int i = 0; i < arr.size(); i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i] );
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > mini ) minimum2 = min(minimum2, arr[i]);
        if (arr[i] < maxi ) maximum2 = max(arr[i] , maximum2);}
    DisplayOutput(minimum2 ,maximum2 );
}

void Method3_best_optimized_Solution(vector<int> &arr){
    int mini  = 1e8 , maxi = -1e8 , minimum2 = 1e8 , maximum2 = -1e8;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < mini){
            minimum2 = mini;
            mini = arr[i];
        }
        else if (arr[i] < minimum2) minimum2 = arr[i];
        if (arr[i] > maxi) {maximum2 = maxi;
        maxi = arr[i];}
        else if (arr[i] > maximum2) maximum2 = arr[i];
    }
    DisplayOutput(minimum2 ,maximum2);

}


int main(){
    cout << endl;
    vector<int> arr = { 2 , 4 , 1 , 2 , 4 , 0 , 0 };

    // Method1_BruteForce(arr);
    
    // Method2(arr);

    // Method3_best_optimized_Solution(arr);

    
    cout << endl;
    return 0;
}
