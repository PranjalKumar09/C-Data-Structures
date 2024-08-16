#include<iostream>
#include<string>
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

vector<int> optimized(vector<int> &arr){
    if (arr.size() <= 2) 
        return arr;
    vector<int> ans(arr.size());
    int negativeIndex = 0 , positiveIndex = 0;
    for (int i = 0 ; i < arr.size() ; i++){
        if (arr[i] > 0)
            positiveIndex++;
        else negativeIndex++;
    }
    if (positiveIndex > negativeIndex) {
        positiveIndex = arr.size() - 1;
        negativeIndex = arr.size() - 2;}
    else {
        negativeIndex = arr.size() - 1;
        positiveIndex = arr.size() - 2;
    }    
    for (int i = 0 ; i < arr.size() ; i++){
        if (arr[i] < 0) {
            ans[negativeIndex] = arr[i];
            negativeIndex -= 2;
            }
        else {
            ans[positiveIndex] = arr[i];
            positiveIndex -= 2;
        }
    }
    return ans;
    }


int main(){
    cout << endl;

    vector<int> arr = {1,-2,-2,-2 , -3, -4, -1, 4};
    vector<int> ans = optimized(arr);
    display(ans);
    
    
    cout << endl;
    return 0;
}