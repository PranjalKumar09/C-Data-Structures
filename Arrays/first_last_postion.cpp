/* 
in binary there is seprate function for first and last but in BF it is in one loop
further it BS can solved direct (recommended) and  recusive 
but still binary search is better(direct one)



 */
#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;


void display_output(vector<int> &arr){
    if (arr[0] == -1)
        cout << " No first postion and last postion not founf" << endl;
    else 
        cout << " First postion is at " << arr[0] << endl << " index Last postion is " << arr[1] << endl;

}

vector<int> brute_force(vector<int> &arr, int target){
    int first = -1, last = -1 ;
    for (int i = 0 ; i < arr.size() ; i++){
        if (target != arr[i]) continue;
        if (first == -1) first = i;
        last = i;}
    return {first, last};
}

int first_position(vector<int> &arr , int target){
    int start = 0 , end = arr.size() - 1 , ans = -1 ; 
    while (start <= end){
        int mid = start + (end - start) / 2;
        if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
            if (arr[mid] == target) ans = mid;
        }
    }
    return ans;
}

int end_position(vector<int> &arr , int target){
    int start = 0 , end = arr.size() - 1 , ans = -1;
    while (start <= end){
        int mid = start + (end - start) / 2;
        if (arr[mid] > target) {    
            end = mid - 1;
        } else {
            start = mid + 1;
            if (arr[mid] == target) ans = mid;
        }
    }
    return ans;
}

vector<int> binary_sesrch_mehtod(vector<int> &arr , int target){
    return {first_position(arr , target) , end_position(arr , target)};
}

int main() {

    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int target = 5;

    // vector<int> ans = brute_force(arr, target);
    // display_output(ans);
    
    vector<int> ans2 = binary_sesrch_mehtod(arr , target);
    display_output(ans2);



    cout << endl;
    return 0;
}