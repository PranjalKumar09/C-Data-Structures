/* 
Note-> ALl arrays will sorted */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void common_element_in_sorted_arrayy(vector<int> arr1  , vector<int> arr2  , vector<int> arr3   ){
    int i = 0 , j = 0 , k = 0;
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()){
        if (arr1[i] == arr2[j] && arr1[i] == arr3[k]){
            cout << arr1[i] << " ";
            i++;
            j++;
            k++;
        }
        else if (arr1[i] < arr2[j] || arr1[i] < arr3[k] )i++;
        else if (arr2[j] < arr3[k] || arr2[j] < arr1[i] )j++;
        else  k++;
    }
}

int main(){
    
    vector<int> arr1  = {1, 5, 10, 20, 40, 80} ;
    vector<int> arr2 = {6, 7, 20, 80, 100} ;
    vector<int> arr3  = {3, 4, 15, 20, 30, 70, 80, 120} ;
    common_element_in_sorted_arrayy(arr1, arr2, arr3);

    cout << endl;
    return 0;
}