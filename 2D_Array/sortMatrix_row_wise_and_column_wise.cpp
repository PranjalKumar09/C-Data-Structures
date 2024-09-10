
/* 
Sort each row of the matrix.
Get transpose of the matrix.
Again sort each row of the matrix.
Again get transpose of the matrix.

 */





#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



void display(vector<vector<int>> &arr){
    cout << "{ ";
    for (int j = 0; j < arr.size();j++){
        cout  << " { ";
        int size = arr[0].size();
        for (int i = 0 ; i < size - 1 ; i ++)
            cout <<  arr[j][i] << " , ";
        cout << arr[j][size-1] << " } ";
        if (j!= arr.size() - 1) cout << endl; 
    }
    cout << " }" << endl;
}

void sort_matrix_row_and_column_wise(vector <vector<int>> &matrix){
    for (int i = 0; i < matrix.size(); i++)
    sort(matrix[i].begin(), matrix[i].end());
  
    for (int i = 0; i < matrix.size(); i++){
        for (int j = i+1 ; j < matrix.size() ; j++)
            swap(matrix[i][j] , matrix[j][i]);
    }

    for (int i = 0; i < matrix.size(); i++)
    sort(matrix[i].begin(), matrix[i].end());

  
    for (int i = 0; i < matrix.size(); i++){
        for (int j = i+1 ; j < matrix.size() ; j++)
            swap(matrix[i][j] , matrix[j][i]);
    }
}
int main(){
    cout << endl;
    
     vector<vector<int>> matrix1 =  { {4, 1, 3},
                    {9, 6, 8},
                    {5, 2, 7} };


    sort_matrix_row_and_column_wise(matrix1);
    display(matrix1);

    cout << endl;
    return 0;
}
