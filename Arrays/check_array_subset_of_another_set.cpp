#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool brute_force(vector<int> &arr1 , vector<int> &arr2){
    int j;
    for (int i = 0; i < arr2.size(); i++) {
        for ( j = 0; j < arr1.size(); j++) 
            if (arr1[j] == arr2[i])  break;
           
        
        if (j == arr1.size())   return false;
    }
    return true;
}




bool binary_Search(vector<int> &arr1  , int target){
    int left = 0;
    int right = arr1.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr1[mid] == target) 
            return true;

        else if (arr1[mid] < target) 
            left = mid + 1;
        
        else 
            right = mid - 1;
        
    }
    return false;
}
bool method2(vector<int> &arr1 , vector<int> &arr2){
    sort(arr1.begin(), arr1.end());
    for (int i = 0; i < arr2.size(); i++) 
        if (!binary_Search(arr1, arr2[i])) return false;
    
    return true;
}

 

bool optimized(vector<int> &arr1 , vector<int> &arr2){
    map <int, int> occr  ;
    for (int i = 0; i < arr1.size(); i++) occr[arr1[i]]++;
    for (int i = 0; i < arr2.size(); i++) occr[arr2[i]]--;
    for (auto temo: occr) if (temo.second < 0 ) return false;
    return true;
}


int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5, 6} , arr2 =  {1, 2, 4 } ; 
    cout << brute_force(arr1 , arr2) << endl;
    cout << method2(arr1, arr2) << endl;
    cout << optimized(arr1, arr2) << endl;
    return 0;
}