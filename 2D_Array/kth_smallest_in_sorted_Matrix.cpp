#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int counter(vector <vector <int> > & matrix , int k , int mid){
    int count = 0;
    for (int i = 0;  i < matrix.size() ; i++){
        for (int j =  matrix[i].size() - 1;  j >= 0 ; j--){
            if (matrix[i][j] <= mid)
               { count += j+1;
                break;}
            
        }    }
    return count;
}



int kth_smallest(vector<vector<int>> & arr, int k ){
    int low = 0 , high = arr[arr.size()-1][arr[0].size() - 1];
    while (low < high){
        int mid = low + (high - low) / 2;
        int count = counter(arr, k, mid);
        if ( count >= k) high = mid;
        else low = mid + 1;
    }
    return low;
}


int main(){
    cout << endl;

    
     vector<vector<int>> matrix1 =  {{5, 10, 15, 20},
                                    {25, 30, 35, 40},
                                    {45, 50, 55, 60},
                                    {65, 70, 75, 80}};

    cout << kth_smallest(matrix1, 3);
    cout << endl;
    return 0;
}
