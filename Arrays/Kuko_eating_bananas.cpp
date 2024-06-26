/* 
So you know that H will be atleast sizeof array  => H >= SIZE

maximum which answer is possible is maximum in array because it will take it as 1 and rest as also 1 so it is maximum possible answer 

so range 1 to maxi 


So in brute force we are first finding maximum element 

TC : O(max(a[]) * N), where max(a[]) is the maximum element in the array and N = size of the array.
Reason: We are running nested loops. The outer loop runs for max(a[]) times in the worst case and the inner loop runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.




Now binary search 
by observation it is know that 

TC: O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array.
Reason: We are applying Binary search for the range [1, max(a[])], and for every value of ‘mid’, we are traversing the entire array inside the function named calculateTotalHours().

SC: O(1)



 */










#include <iostream>
#include <vector>
#include <climits>

using namespace std; 

bool Brute_force_func(vector<int> &arr, int H, int temp) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        count += (arr[i] / temp);
        if (arr[i] % temp != 0) count += 1;
    }
    return (count <= H);
}

int Brute_force(vector<int> &arr, int H) {
    int maxi = -1;
    for (int i = 0; i < arr.size(); i++) maxi = max(maxi, arr[i]);
    for (int i = 1; i <= maxi; i++)
        if (Brute_force_func(arr, H, i)) return i;

    return -1;
}


int binarySearch(vector<int> &arr, int H){
    int low = 1  ,  high = -1 ,ans = -1;
    for (int i = 0; i < arr.size(); i++) high = max(high, arr[i]);

    while (low <= high   ){
        int mid = low + (high - low)/2;
        if (Brute_force_func(arr, H, mid)) {
            ans = mid;
            high = mid - 1;
            }
        else low = mid + 1;
    }
    return ans;
}

int main(){
    cout << endl;

    vector<int>  arr =  {25, 12, 8, 14, 19};
    int  H = 5;
    cout << binarySearch(arr,H) ;
    

    cout << endl;
    return 0;
}