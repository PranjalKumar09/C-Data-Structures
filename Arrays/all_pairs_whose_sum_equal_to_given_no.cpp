#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> BruteForce_all_pairs_sum_equal_to_target(vector<int> &arr , int targetSum){
    vector<pair<int, int>> ans;
    for (int i = 0; i < arr.size(); i++)
        for (int j = i+1; j < arr.size(); j++)    if (arr[i] + arr[j] == targetSum) ans.push_back({arr[i] , arr[j]});
    return ans;}

vector<pair<int, int>> Optimized_all_pairs_sum_equal_to_target(vector<int> &arr , int targetSum){
    vector<pair<int, int>> ans;
    sort(arr.begin(),arr.end());
    int start = 0 , end = arr.size() - 1;
    while(start < end){
        if(arr[start] + arr[end] == targetSum){
            ans.push_back({arr[start],arr[end]});
            start++;
            end--;
        }
        else if(arr[start] + arr[end] < targetSum)    start++;
        else end--;
    }
    return ans;
}




int main(){

    vector<int> arr = {-5, 1, -40, 20, 6, 8, 7 };
    int targetSum = 15;
    // vector<pair<int, int>> ans = BruteForce_all_pairs_sum_equal_to_target(arr,targetSum);
    vector<pair<int, int>> ans = Optimized_all_pairs_sum_equal_to_target(arr,targetSum);
    for (int i = 0 ; i < ans.size() ; i++)        cout << ans[i].first << " " << ans[i].second << endl;
    




    
    cout << endl;
    return 0;
}