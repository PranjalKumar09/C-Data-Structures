/*
BruteForce : Copy non zero to temp array , then copy temp array element to original then fill zero

Optimized : 2 pointer approach
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void display(vector<int> &arr){
    cout << endl << "{ ";
    int size = arr.size();
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " }";
}

void BruteForce(vector<int> &arr){
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) temp.push_back(arr[i]);
    }
    for (int i = 0; i < arr.size(); i++) 
        i < temp.size() ?  arr[i] = temp[i]: arr[i] = 0;
}

void OptmizedSolution(vector<int> &arr){
    int j = arr.size()-1;
    for (int i = 0; i <= j; i++)if (arr[i] == 0) {swap(arr[i] , arr[j]); j--;}
    }
    
        


int main(){
    cout << endl;

    vector<int> arr = {0,2,0,4,1,2,4};
    display(arr);
    //BruteForce
    // BruteForce(arr);
    // display(arr);

    //
    OptmizedSolution(arr);
    display(arr);






    cout << endl;
    return 0;
}
