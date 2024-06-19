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


void BubbleSort_Recursive(vector<int> &Array, int num){// num here is size of array
    if (num < 0) return;
    bool did_swap = false;
    for(int j = 0 ; j < num ; j++){
        if (Array[j] > Array[j+1]) {swap(Array[j], Array[j+1]);
        did_swap = true;}
    }
    if (!did_swap) return; 
    return BubbleSort_Recursive(Array , num-1);
    }   

void BubbleSort(vector<int> &Array){
    for (int i = Array.size() - 1 ; i >= 0 ; i--){
        bool did_swap = false;
        for (int j = 0 ; j < i ; j++){
            if (Array[j] > Array[j+1]) {
                swap(Array[j], Array[j+1]);
                did_swap = 1;}
        if (!did_swap) break;}}}


int main(){
    cout << endl;
    
    vector<int>  array = {4,3,2,1};
    display(array);
    // BubbleSort(array); //Reommended to use that recursive function
    // BubbleSort_Recursive(array , array.size()); //Both works here 
    display(array);
    cout << endl;
    return 0;
}
