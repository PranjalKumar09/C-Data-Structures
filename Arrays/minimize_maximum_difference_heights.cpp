/*  NOTE: we have to minimize the maximum difference by either increasing or decreasing the number by k, and return maximum difference BUT it is only asking difference so in reality we have to just return difference int , nor vector, so performed fn will give that */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int fn(vector<int> arr , int k){
    sort(arr.begin(), arr.end());
    int smallest = arr[0] + k , largest = arr[arr.size()-1] - k, ans = 1e9;
    for(int i = 0; i < arr.size(); i++){
        int mini = min(arr[i]-k, smallest);
        if (mini<0) continue;
        int maxi = max(arr[i-1]+k, largest);
        ans = min(ans,maxi - mini);
    }
    return ans;
    
}

int main(){
    cout << endl;
    
    vector<int> array = {1,15,10};
    int k = 6;
    cout << "Maximum difference is " <<  fn(array, k) << endl; 
    
    cout << endl;
    return 0;
}
