/* 
2 pointter method most optimized 

Time complexity => O(2N)

Initialize left, right, sum, maxLen, and startIndex  to all zero 
while right is less than  array size.
Add the element at index right to the sum.
If the sum equals K, update maxLen and startIndex if the current window size is larger than the previous maximum.
If sum is less than K, expand the window by incrementing right.
If sum is greater than K, shrink the window from the left side until sum becomes less than or equal to K.
Repeat until right reaches the end of the array.
Finally, construct the result vector ans by pushing elements from startIndex to startIndex + maxLen - 1.

 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void display(vector<int> &arr){
    cout << endl << "{ ";
    int size = arr.size();
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " }";
}


vector<int> BruteForce3nested_largest_subarray_with_sum_k(vector<int> &arr , int k){
    vector<int> ans ;
    int max_size = 0;
    for (int i = 0; i < arr.size(); i++){
        for(int j =  i; j < arr.size(); j++){
            int sum = 0;
            for (int k = i ; k <= j ; k++)
                sum += arr[k];
            if(sum == k && max_size < j-i+1 ){
                ans.clear();
                for (int k = i; k <= j; k++) ans.push_back(arr[k]);
                max_size =  j-i+1 ;}  }}
    return ans;
}
vector<int> BruteForce2nested_largest_subarray_with_sum_k(vector<int> &arr , int k){
    vector<int> ans ;
    int max_size = 0 , startindex = 0;
    for (int i = 0 ; i < arr.size(); i++){
            int sum = 0; 
        for (int j =  i; j < arr.size() ; j++){
            sum += arr[j];
            if (sum == k && max_size < j-i+1){
                max_size = j-i+1 ;
                startindex = i ;
            }

        }
    }
    for (int i = startindex; i < startindex + max_size; i++)
        ans.push_back(arr[i]);
    return ans;
}
// This not working 
// vector<int> pointer_method_argest_subarray_with_sum_k(vector<int> &arr , int k){
//     vector<int> ans ;
//     int left = 0, right = 0, max_size = 0 , startindex = 0, sum  = 0; 
//     while (right < arr.size()){
//         while(left <= right && sum >k)
//             sum -= arr[left++];
    
//         if (sum==k  && max_size < right-left+1){
//                max_size =right-left ;  // note acutally left i
//                startindex = left ;
//             }
//         if (right < arr.size()) sum+=arr[right++];
//         cout << " Left: " << left << " Right: " << right << " Max size: " << max_size  << " Sum: " << sum << endl ; 
//     }
//     for (int i = startindex; i < startindex + max_size; i++)
//         ans.push_back(arr[i]);
      
//     return ans;
// }

vector<int> pointer_method_argest_subarray_with_sum_k(vector<int> &arr , int K)
{
    vector <int> ans;
    int left = 0, right = 0, sum = 0 , maxLen = -11, startIndex = 0;
   
    while (right < arr.size()) {
        sum += arr[right];  //calculation
        if (sum == K) { 
            if (maxLen < right - left +  1)  {
                maxLen =   right - left +  1 ;  //taking results
                startIndex = left;}
            right++;
        }
        else if (sum < K)     //adjusting window
            right++;
        else if (sum > K) {     //adjusting window
            while (sum > K) {
                sum -= arr[left];
                 left++;
            }
            if (maxLen < right - left +  1)  {
                maxLen =   right - left +  1 ;  //taking results
                startIndex = left;}
            right++;
        }
    }
    for (int i = startIndex; i < startIndex + maxLen; i++)
        ans.push_back(arr[i]);    
    return ans;
}

int main(){
    cout << endl;
    vector<int> arr = { 10, 5, 2, 7, 1, 9 ,2};
    int k = 15;
    // vector<int> ans = BruteForce3nested_largest_subarray_with_sum_k(arr, k) ;
    vector<int> ans = pointer_method_argest_subarray_with_sum_k(arr, k) ;

    display(ans);
    

    
    cout << endl;
    return 0;
}