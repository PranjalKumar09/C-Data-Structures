/* 


Note the value of end will  array.size() * array[0].size() - 1 

NOT (arra.size() - 1 ) * (array.size() - 1)
 */


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool Binary_search(vector<vector<int> >& array , int target){
    int start = 0;
    int end = array.size() * array[0].size() - 1 ;
    while ( start <= end){
        int mid = start + (end - start) / 2;
        if(array[mid/array[0].size()][mid%array[0].size()] == target ) return true ; 
        else if(array[mid/array[0].size()][mid%array[0].size()] < target) start = mid + 1 ;
        else end = mid - 1 ;
    }
    return false ;
}

int main(){
    cout << endl;
    
     vector<vector<int> > arr = { { 1, 2, 3, 4 },
                              { 5, 6, 7, 8 },
                              { 9, 10, 11, 12 } };
    cout << Binary_search(arr, 9) << endl;
 
    cout << endl;
    return 0;
}

