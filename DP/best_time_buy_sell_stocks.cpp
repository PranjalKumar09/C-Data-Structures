
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int k, n;



/* 
    Buying stocks, once maximum profit


    if  i a buying at ith day i must will do cost from day from day on  start to that day

 */

int maxProfit(vector<int> &arr){
    int maxProfit = 0;
    int mini = INT_MAX;
    for (int i = 0; i < arr.size();i++){
        mini = min(mini, arr[i]);
        maxProfit = max(maxProfit, arr[i] - mini);
    }
    return maxProfit;
}






int main(){
    arr = {7, 1, 5, 3, 6, 4};

    n = arr.size();
    cout << maxProfit(arr) << endl;

    return 0;  // Return 0 to indicate successful program execution
}