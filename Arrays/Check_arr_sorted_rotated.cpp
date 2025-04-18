#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check_rotated_sorted(vector<int> &arr){
    if (arr.size() == 0 || arr.size() == 1) return true; 

    int count = 0;
    if (arr[arr.size()-1] > arr[0]) count++;
    for(int i = 1; i < arr.size(); i++)
        if(arr[i-1] > arr[i])            count++;
    
    //count = 0 for EXECPTION = {1,1,1} to deal 
    return count == 1 || count == 0;
}

bool isSorted(vector<int>& arr, int start, int end) {
    if (start == end) // only one element
        return true;
    
    int mid = start + (end - start) / 2; // Calculate the mid index

    // Check if the array is sorted in the left half or right half
    if (arr[mid] > arr[end]) {
        // If the right half is unsorted, recursively check the left half
        return isSorted(arr, start, mid);
        /* Recursive Analysis: By observing arr[mid] > arr[end], we know that the right half is not sorted. However, we can't conclude whether the entire array is unsorted or not until we examine the left half as well.

        Inductive Reasoning: Imagine we have a rotated sorted array. Even though one half might not be sorted, the other half could still maintain the sorted order.

        Divide and Conquer Approach: The recursive function employs a divide and conquer strategy. It divides the problem into smaller subproblems and solves each subproblem independently. So, when we encounter an unsorted half, we recursively focus on that half to check its sortedness.

        Base Case Handling: The recursion stops when we reach a base case where there's only one element. At that point, we return true because a single element is always considered sorted. */
    } else if (arr[start] > arr[mid + 1]) {
        // If the left half is unsorted, recursively check the right half
        return isSorted(arr, mid + 1, end);
    } else {
       // Check if all elements within the range [start, end] are sorted
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }
}

bool check_rotated_sorted_recursive(vector<int>& arr) {
    if (arr.empty()) // If the array is empty, it's considered sorted
        return true;
    return isSorted(arr, 0, arr.size() - 1);
}
int main(){
    cout << endl;

    vector<int> arr = { 1,1,1 ,2,2,3,9,4,2}; 
    //   check_rotated_sorted(arr)? cout << "Yes, it is rotated and sorted" : cout << "No, it is not rotated and not sorted" ;  // this one is better than the recursive
    check_rotated_sorted_recursive(arr)? cout << "Yes, it is rotated and sorted" : cout << "No, it is not rotated and not sorted" ; 
    
    
    cout << endl;
    return 0;
}