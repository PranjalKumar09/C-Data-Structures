#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>


using namespace std;

int brute_force(vector<int> &arr){
    int maxi = -1;
    for (int i = 0 ; i < arr.size() ; i++){
        int temp = arr[i];
        for (int j = i+1  ; j < arr.size() ; j++){
            temp *= arr[j];
            maxi = max(maxi, temp);}}
    return maxi;
}



int kardane_algorithm(vector <int> &arr){
    int prod1 = arr[0] , prod2 = arr[0]  , result = arr[0];
    for (int i = 1 ; i < arr.size() ; i++){
        int temp = max({arr[i] , prod1 * arr[i] , prod2 * arr[i]});
        prod2 = min({arr[i] , prod1 * arr[i] , prod2 * arr[i]});
        prod1 = temp;

        result = max(result , prod1); 
    }
    return result;
}

int main(){
    cout << endl;


 





    vector<int> arr = { 1, -2, -3, 0, 7, -8, -2 }; 
    cout << kardane_algorithm(arr) << endl;
    




    cout << endl;
    return 0;
}