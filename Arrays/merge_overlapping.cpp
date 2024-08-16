#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void temp_display(vector<int> &arr){
    cout  << " { ";
    int size = arr.size();
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " } ";
}

void display(vector<vector<int>> &arr){
    cout << "{ ";
    for (int i = 0; i < arr.size();i++)temp_display(arr[i]);
    cout << " }" << endl;
}

vector<vector<int>> merge_overlapping_interval(vector<vector<int>> &arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++){
        if( ans.empty() || arr[i][0] > ans.back()[1])  ans.push_back(arr[i]) ;
        else ans.back()[1] =  max(ans.back()[1] , arr[i][1]);

    }    return ans;
}

int main(){
    cout << endl;

    vector<vector<int>> array = {{1,3},{2,4},{6,8},{9,10}};
    vector<vector<int>> ans = merge_overlapping_interval(array);
    display(ans);

    
    
    cout << endl;
    return 0;
}