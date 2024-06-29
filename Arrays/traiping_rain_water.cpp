#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int brute_force(vector<int> &arr){
    int n = arr.size() , total = 0;
    for (int i = 0 ; i < n ; i++){
        int j = i;
        int leftMax = 0 , rightMax = 0;
        while (j >= 0){
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;
        while (j < n){
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        total += min(leftMax, rightMax) - arr[i];
    }    
    return total;
}


int better(vector<int> &arr){
    int n = arr.size() , total = 0;
    vector<int> prefix(n , arr[0]) , suffix(n , arr[n-1]) ; 
    for (int i = 1 ; i < n ; i++){
        prefix[i] = max(prefix[i-1], arr[i]);
        suffix[n-i-1] = max(suffix[n-i], arr[n-i-1]);
    }
    for (int i = 0 ; i < n ; i++)
        total += min(prefix[i], suffix[i]) - arr[i];
    
    

    return total; 
}

int two_pojinter_approach(vector<int> &arr){
    int n = arr.size(), total = 0;
    int left, right, left_max, right_max;
    left = left_max = right_max = 0;
    right = n - 1;

    while (left < right) {
        if (arr[left] < arr[right]) {
            if (arr[left] >= left_max)
                left_max = arr[left];
            else
                total += left_max - arr[left];
            left++;
        } else {
            if (arr[right] >= right_max)
                right_max = arr[right];
            else
                total += right_max - arr[right];
            right--;
        }
    }

    return total;
}


int main(){

    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "The water that can be trapped is " << brute_force(arr) << endl;
    cout << "The water that can be trapped is " << better(arr) << endl;
    cout << "The water that can be trapped is " << two_pojinter_approach(arr) << endl;
    






    
    cout << endl;
    return 0;
}