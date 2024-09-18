#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;


int Brute_Force(vector<int>& arr){
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) count++;
    }
    return count;
}




// Method 2 


int merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;

    int left = low  , right = mid+1  , inv_count = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        
        else{
            temp.push_back(arr[right++]);
            inv_count += (mid - left + 1); 
        }
    }
    while(left <= mid)
        temp.push_back(arr[left++]);
    
    while(right <= high)
        temp.push_back(arr[right++]);
    
    for(int i = low; i <= high; i++)
        arr[i] = temp[i-low];
    return inv_count;

}
    


int merge_sort(vector<int>& arr,  int l, int r){
    int mid , inv_count = 0;

    if (l < r){
        int mid  = l + (r - l)/2;
        inv_count += merge_sort(arr , l , mid);
        inv_count += merge_sort(arr,  mid+1, r);
        inv_count += merge(arr,  l, mid, r);
    }
    return inv_count;
}
    

int intersection(vector<int>& arr){
    int size = arr.size();
    return merge_sort(arr , 0 , size-1);
}


int main(){
    vector<int> arr = {4,2,0,3,2,5} ;
    cout << "brute_force : " << Brute_Force(arr) << endl;
    cout << "merge sort method : " << intersection(arr) << endl;



    return 0;
}