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

int Optimized_find_specific_pair(vector <vector<int>> &matrix){
    int N =  matrix.size() , C = matrix[0].size();
     if (N < 2 || C < 2) return -1;
    

    vector<vector<int> > temp(N-1 ,vector<int>(C- 1 )) ;
    temp[N- 2][C - 2] = matrix[N - 1][C - 1] ;
    for (int i = N-3; i >= 0; i--)
        temp[i][C-2] = max (matrix[i+1][C-2] , temp[i+1][C-2]);
    for (int i = C-3; i >= 0 ; i--)
        temp[N-2][i] = max (matrix[N-2][i+1] , temp[N-2][i+1]);
    // display (temp);
    for (int i = N-3;  i  >= 0; i--){
        for (int j = C-3; j >= 0  ; j--)
        temp[i][j] = max (max(matrix[i+1][j+1], temp[i+1][j+1]) , max( temp[i+1][j] ,temp[i][j+1] )) ; 
    }
    int ans = -1;
    for (int i = 0; i < N-1 ; i++){
        for(int j = 0; j < C-1 ; j++)
        ans = max(ans,temp[i][j] - matrix[i][j]);}
    return ans;}


int Brute_Force_find_specific_pair(vector <vector<int>> &matrix){
    int maxi = -1;
    for (int i = 0 ; i < matrix.size() ; i++){
        for (int j = 0 ; j < matrix[i].size() ; j++){
            int temp = -1 ; 
            for (int k = i + 1 ; k < matrix.size() ; k++){
                for (int l = j + 1 ; l < matrix[k].size() ; l++){
                    maxi = max(maxi, matrix[k][l] - matrix[i][j]);
            }
        }
    }
}
    return maxi;
}
int main(){
    cout << endl;

    
     vector<vector<int>> matrix1 =  {{5, 10, 15, 20},
                                    {25, 30, 35, 40},
                                    {45, 50, 55, 60},
                                    {65, 70, 75, 80}};

    cout << Optimized_find_specific_pair(matrix1) << " " << Brute_Force_find_specific_pair(matrix1) ;

    cout << endl;
    return 0;
}
