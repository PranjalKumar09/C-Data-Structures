#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sumByRow( vector<vector<int>> &arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            sum+=arr[i][j];
        }
    }
    return sum;
} 

int sumByColumn( vector<vector<int>> &arr){
    int sum=0;
    for(int i=0;i<arr[0].size();i++){
        for (int j=0;j<arr.size();j++){
            sum += arr[j][i];
    
    }
}
    return sum;
}

int main(){
    cout << endl;

   
    vector<vector<int>> arr =  { { 3, 12 }, { 5, 2 }, { 90, 45 } };
    cout << sumByColumn(arr) << " " << sumByRow(arr);
    
    cout << endl;
    return 0;
}

