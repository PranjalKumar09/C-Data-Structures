/* 
Q- >  Max profit in stock Buy ans sell 
i/p prices[i] day->
select day to buy and sell stock to get max profit */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display_the_result(vector<int> prices){
    cout << "Stock should be buyied in " << prices[0] << " and sell in " << prices[1];
}

vector<int> brute_force(vector<int> arr){
    vector<int> ans(2,-1);
    int maxi = -1;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i+1; j < arr.size(); j++){
            if (arr[j] - arr[i] > maxi) {
                maxi = arr[j] - arr[i];
                ans[0] = i;
                ans[1] = j;}
        }
    }
    ans[0] = ans[1] - ans[0] < 0 ? -1 : ans[0]; // If no profitable transaction, set buy and sell days to -1
    return ans;
}

vector<int> optimized(vector<int> arr){
    vector<int> ans(2,-1);
    int miniPrice = 1e9 , maxiPrice = -1;
    for (int i = 0; i < arr.size(); i++){
        if (miniPrice > arr[i]) {
            miniPrice = arr[i];
            ans[0] = i;
        }
        else if (arr[i] - miniPrice > maxiPrice) {
            maxiPrice = arr[i] - miniPrice;
            ans[1] = i;
        }
    }
    ans[0] = ans[1] - ans[0] < 0 ? -1 : ans[0]; // If no profitable transaction, set buy and sell days to -1
    return ans;
}

int main(){
    cout << endl;
    vector<int> arr = {100, 180, 260, 310, 40, 535, 695}    ;
    vector<int> ans = brute_force(arr);
    // vector<int> ans = optimized(arr);

    display_the_result(ans);
    
    cout << endl;
    return 0;
}