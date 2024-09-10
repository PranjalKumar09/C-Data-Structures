#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


int solution(vector<int> & arr , int students){
    int ans = INT_MAX;
    sort(arr.begin(), arr.end());
    for (int i  = 0 ; i <= arr.size() - students ; i++)
        ans = min(ans , arr[i+students-1] - arr[i]);
    return ans;
}

int main(){
    vector<int> arr = {6,8,11,21,90,49} ; 
    int students = 4;
    cout << solution(arr , students) << endl;



    return 0;
}