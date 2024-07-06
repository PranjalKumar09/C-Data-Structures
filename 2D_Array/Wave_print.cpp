#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Wave_Print(vector<vector<int>> &arr){
    if (arr.size() < 1) return;
    for (int i = 0; i < arr[0].size(); i++){
        if ( i & 1)
            for (int j = arr.size() - 1; j >= 0; j--) cout << arr[j][i] << " ";  
        else 
            for (int j = 0 ; j < arr.size() ; j++) cout << arr[j][i] << " ";
    }
}


int main(){
    cout << endl;

   
    vector<vector<int>> arr =  {{  1,   2,   3,   4},
                                {  5,   6,   7,   8}, 
                                {  9,  10,  11,  12},
                                { 13,  14,  15 , 16},
                                { 17,  18,  19,  20}};
    Wave_Print(arr);
    
    cout << endl;
    return 0;
}

