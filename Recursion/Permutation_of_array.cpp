/* 
Method1 (using solve function):

    Time Complexity: O(n!×n)
    Space Complexity: O(n!×n

Method2 (using Method2 function):

    Time Complexity: O(n!×n
    Space Complexity: O(n)


 */


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector<vector<int> > & num){
    for (int i = 0; i < num.size(); i++) {
        for (int j = 0; j < num[i].size(); j++) {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
}


void solve(vector<int>& nums , vector<vector<int>> & solution , int index){
    if (index>=nums.size()) 
    {   solution.push_back(nums);
        return;}
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        solve(nums,solution,index+1);
        swap(nums[index],nums[i]);
    }
}



void print_vector( vector<int>& vec) {
    for (int num : vec) 
        cout << num << " ";
    
    cout << endl;
}

void Method2(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    do print_vector(vec);
    while (next_permutation(vec.begin(), vec.end()));
}


int main(){
    cout << endl;

    vector< int > nums = {10, 20, 30, 40};
    vector< vector<int>> ans ;
    // solve(nums , ans , 0);
    // display(ans);
    Method2(nums);

    cout << endl;
    return 0;
}