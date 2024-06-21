#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int BruteForce_count_pair_with_given_sum(int arr[] , int k , int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==k){
                count++;
            }
        }
    }
    return count;
}

int Optimized_count_pair_with_given_sum(int arr[] , int k , int n){
    sort(arr,arr+n);
    /* // this method easy & better 
     int count=0, start = 0 , end = n-1;
    while(start < end){
        if(arr[start]+arr[end]==k){
            count++;
            start++;
            end--;
        }
        else if(arr[start]+arr[end]<k)    start++;
        else    end--;
    } */
    int count=0;
    for(int i=0;i<n-1;i++){
        int sum_left = k -arr[i];
        int y = lower_bound(arr+i+1, arr+n , sum_left) - arr;
        int z = upper_bound(arr+i+1, arr+n, sum_left) - arr;
        count += z-y;
    }
    return count;
}

int main(){
    
    int arr[] = {1, 5, 7, -1}, K = 6 ; 
    int size =sizeof(arr)/sizeof(arr[0]);

    cout << BruteForce_count_pair_with_given_sum(arr, K , size ) << endl;
    cout << Optimized_count_pair_with_given_sum(arr, K , size);
    
    cout << endl;
    return 0;
}