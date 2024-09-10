//NOT SOLVED 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int brute_force_maximum_no_of_jumps(vector<int> &arr, int index){ 
    if ( index >= arr.size()-1) return 0; 
    int max_jumps =  arr[index];
    for (int i = 1; i <= arr[index]; i++){
        int jumps = brute_force_maximum_no_of_jumps(arr, index+i);
        max_jumps = max(max_jumps, jumps);
    }
    cout << "max_jumps: " << max_jumps <<" INDEX "<< index << endl;
    return max_jumps;
}



int optimized_solution_maximum_no_of_jumps(vector<int> &arr){  
    if (arr.size()<=1) return 0; 
    int currMaxJumps = arr[0];
    int steps_Count = arr[0] , jumps = 0;
    for (int start = 1; start < arr.size()-1; start++){
        currMaxJumps = max(currMaxJumps, start + arr[start]);
    steps_Count = steps_Count-1;
    if (steps_Count == 0){
        jumps++;
        steps_Count = abs(currMaxJumps-start);
    }
    }
    return jumps+1;
}


int main(){
    cout << endl;
    
    vector<int> arr = {2, 3, 5, 7, 9};
    // cout << "Brute force maximum no of jumps: " << brute_force_maximum_no_of_jumps(arr, 0) << endl;
    cout << "Optimized solution maximum no of jumps: " << optimized_solution_maximum_no_of_jumps(arr) << endl;
    
    
    cout << endl;
    return 0;
}