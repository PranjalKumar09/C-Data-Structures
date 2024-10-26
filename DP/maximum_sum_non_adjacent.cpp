// Apply better recursion by PICK AND NON PICK

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// PREVIOUS RECURSION WITH LOT OF IF ELSE  RATHER APPLY EFFECTIVE RECURSION

int recursion(vector<int> &arr, int num){
    if (num == 0) return max(arr[0], 0);
    if (num < 0) return 0;
    int not_pick = recursion(arr, num-1);
    int pick = recursion(arr, num-2) + arr[num];
    return max(not_pick, pick);
}

int recursion_memorization(vector<int>& arr, int num , vector<int>& memorization){
    if (num < 0 ) return 0;
    if (memorization[num]!= -1) return memorization[num];
    int not_pick = recursion_memorization(arr, num-1, memorization);
    int pick = recursion_memorization(arr, num-2, memorization) + arr[num];
    memorization[num] = max(not_pick, pick);
    return memorization[num];
}

int Tabulation(vector<int>& arr, int num){
    vector<int>  memorization(num, - 1);
    memorization[0] = max(0, arr[0]);
    memorization[1] = max(1, arr[1]);
    for (int i = 2 ; i <= num ; i++){
        int not_pick = memorization[i-1];

        int pick = memorization[i-2] + arr[i];
        memorization[i] = max(not_pick, pick);
    }
    return memorization[num-1];
}

/* int dp(vector<int> &arr, int num){
    int pick = arr[0];
    int not_pick = 0, maxi = pick; 
    for (int i = 1 ; i < num ; i++) {
        not_pick = max(not_pick, 
    }
}
 */



int main(){
    cout << endl;
    
    vector<int> arr = {1,2,4};
    
    cout << recursion(arr , arr.size() - 1) << endl; // method 1 

    // method 2 Memorization

    vector<int> memorization(arr.size(), -1);
    memorization[0] = max(arr[0] , 0);
    cout << recursion_memorization(arr, arr.size() - 1, memorization) << endl; 

    // method 3 dp

    cout << Tabulation(arr, arr.size() ) << endl;






    cout << endl;
    return 0;
}
