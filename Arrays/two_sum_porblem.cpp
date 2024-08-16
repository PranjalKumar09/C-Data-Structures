/* 
By hashing the TC and SC will wrost then Optimized also if same elmenent will causse error like if target  = 10 and if elemennt is 5 it will given always true because here it will always search target - arr[i] which is 5 .whether other elment 5 exist or not
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool BruteForce1(vector<int> &arr , int target){
    for(int i=0;i<arr.size();i++){
        for(int j=0; j<arr.size();j++){
            if (i == j) continue;
            if (arr[i] + arr[j] == target)
                return true;
        }}
    return false;
}
bool BruteForce2(vector<int> &arr , int target){
    for(int i=0;i<arr.size();i++){
        for(int j= i+1 ; j<arr.size(); j++){
            if (arr[i] + arr[j] == target)return true;}
        }
    return false;
}



bool Optiimized(vector<int> &arr , int target){
    sort(arr.begin(), arr.end());
    int start = 0 , end = arr.size();
    while(start < end){
        if (arr[start] + arr[end] == target)return true;
        else if (arr[start] + arr[end] < target)start++;
        else end--;}
return false;;}


int main(){
    cout << endl;

    vector <int>  arr = {0, -1, 2, -3, 1};
    int  x= -4; 

    cout << BruteForce1(arr, x) << endl;
    cout << BruteForce2(arr, x) << endl;
    cout << Optiimized(arr, x) << endl;

    
    
    
    cout << endl;
    return 0;
}