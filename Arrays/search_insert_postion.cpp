#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int answer(vector<int> &array , int element){
    int low = 0 , ans  = -1, high = array.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(array[mid] >= element){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans ;
}



int main(){

    vector<int> arr = {1,2,4,7}; 
    int x = 6;

    cout << answer(arr,x) << endl;

    return 0;
}