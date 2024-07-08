/* 
Feature of csorted in row & column side


WHole Process is starting from the right top corner 
                ________________________
                |                |Start |   
                |                |from  |   
                |                | here |   
                |                       |   
                |                       |   
                |                       |   
                |                       |   
                |                       |   
                |                       |   
                |_______________________|
                



 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool Search_in_row_sorted_and_column_sorted(vector<vector<int> >& array , int target){
    int row = 0 , column =array[0].size() - 1;
    while ( row < array.size()  && column >= 0){   // cout << array[row][column]  << " "; 
        if ( target == array[row][column] ) return true;
        else if ( target > array[row][column] ) row++;
        else column--;
        
    }
    return false;
}

int main(){
    cout << endl;
    
     vector<vector<int> > arr = { { 1, 2, 3, 4 },
                              { 5, 6, 7, 8 },
                              { 9, 10, 11, 12 } };
    cout << Search_in_row_sorted_and_column_sorted(arr, 13) << endl;
 
    cout << endl;
    return 0;
}

