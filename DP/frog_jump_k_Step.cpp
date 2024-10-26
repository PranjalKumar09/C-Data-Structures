// NOT SOLVED
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int frog_jump_k_step(vector<int> &arr, int num , int k ){
    if (num == 0) return 0;
    int mini = 1e9;
    for (int i = 1; i <= k &&  i <= num; i++){
        int temp = frog_jump_k_step(arr , num-i,k) + abs(arr[num] - arr[i-1]);
        mini = min(mini, temp);
    }
    return mini;
    }

int main(){
    cout << endl;
    
    vector<int> arr = {2,1,4,9};
    
    cout << endl;
    return 0;
}
