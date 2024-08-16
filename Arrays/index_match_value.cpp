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

int brute_force(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++)
        if (i == arr[i]) return i;
    return -1;
}

int binary_search(vector<int> &arr){
    int low = 0, high = arr.size() - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] == mid) return mid;
        else if (arr[mid] < mid) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}



int main() {

    vector<int> arr =  {-10, -5, 0, 3, 7};
    cout << binary_search(arr) << endl;


    cout << endl;
    return 0;
}