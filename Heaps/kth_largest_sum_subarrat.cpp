#include <bits/stdc++.h>
using namespace std;

/* 
Kth largest Sum of Subarray
===========================

    Method 1: B.F.      TC = O((n log n)^2)     
                        SC = O(n)
                
    Method 2: Using Heap    TC = O(n^2 log k)
                            SC = O(n)
*/      

int solve1(vector<int> &arr, int k){
    vector<int> sumStore;
    for (int i = 0; i < arr.size(); i ++){
        int sum = 0;
        for (int j = i; j < arr.size(); j ++){
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(), sumStore.end());
    return sumStore[sumStore.size()-k];
}
int solve2(vector<int> &arr, int k){
   priority_queue<int , vector<int>, greater<int> > mini;
   for (int i = 0; i < arr.size(); i ++){
        int sum = 0;
        for (int j = i; j < arr.size(); j ++){
        sum += arr[j];
        if (mini.size() < k)
            mini.push(sum);
        
        else{
            if (sum > mini.top()){
                mini.pop();
                mini.push(sum);
            }
        }
    }
   }
   
    return mini.top();
}
int main() {
    vector<int> arr = {1, 12, 9, 5, 6, 10};
    int k = 5;
    cout << solve1(arr, k) << "     " << solve2(arr , k);
}

  