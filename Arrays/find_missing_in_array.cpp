// summation method is here best among all

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Brute_Force_missing_no_in_array(vector<int> &array){
    
    for(int i=1; i<= array.size()+1;i++){
        
        bool check = true;
        for(int j=0;j< array.size();j++){
            if( i == array[j]) check = false;
        }
        if (check) return i;
    }
    return -1;
}
int summation_missing_no_in_array(vector<int> &array){ // total sum = > Formula is n + (n+1)/2 and here n will be array.size() + 1 , +1 because one is missing and we dont have to metion that so putting n value formula => (array.size() + 1 )(array.size() + 2)/2
    int sum = 0;
    for (int i = 0 ; i < array.size() ; i++) sum += array[i];
    return (array.size()+1)*(array.size()+2)/2 - sum;

}
int xor_missing_no_in_array(vector<int> &array){
    int temp = 0;
    for (int i = 0 ; i < array.size() ; i++) temp ^= array[i];
    for (int i = 1 ; i <= array.size() + 1 ; i++) temp ^= i ;
    return temp;
}

int main(){
    cout << endl;

    vector<int> arr =  {3,2,4,5};

    cout << xor_missing_no_in_array(arr);
    
    
    cout << endl;
    return 0;
}