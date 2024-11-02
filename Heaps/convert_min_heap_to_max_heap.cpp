#include <bits/stdc++.h>
using namespace std;

/* 
Convert Min Heap to Max Heap
============================                
    
    Heapify it from to max heap\

    TC = O(n)
    SC = O(n)
*/      

void solve_util(vector<int> &arr, int i , int N){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxi = i;
    if(left < N && arr[left] > arr[maxi])
        maxi = left;
    if(right < N && arr[right] > arr[maxi])
        maxi = right;
    if(maxi!= i){
        swap(arr[i], arr[maxi]);
        solve_util(arr, maxi, N);
    }
}
void solve(vector<int> &arr){
    int N = arr.size();
    for(int i = N/2 - 1; i >= 0; i--)
        solve_util(arr, i, N);
    
}
void print_arr(vector <int> &arr){
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    vector<int> arr = {1,2,3,4,6,10,11,13,16,18,20};
    int k = 5;
    print_arr(arr);
    solve(arr);
    print_arr(arr);
}

  