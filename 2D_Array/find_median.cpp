/* 
Note in uppper bound it only  find the median of odd total elements   */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int brute_force( vector<vector<int>> &matrix){
    vector <int> temp ;
    for(int i=0;i<matrix.size();i++){
        for (int j=0;j<matrix[0].size();j++)
            temp.push_back(matrix[i][j]);
    }
    sort(temp.begin(), temp.end());
    if (temp.size() == 0) return -1;
    if (temp.size() % 2 )
    return temp[temp.size()/2];
    return (temp[temp.size()/2] + temp[temp.size()/2 - 1])/2;
}

int upper_bound_method(vector <vector<int>> &matrix){
    int mini = -1, maxi = -1 ;
    for (int i = 0; i < matrix.size(); i++){
        mini = min(mini , matrix[i][0]);
        maxi = max(maxi, matrix[i][matrix[0].size()-1]);
    }
    int desired  = (matrix.size() * matrix[0].size()  + 1)/2 , mid;
    while ( mini < maxi){

        mid = (mini + maxi)/2;
        int place = 0; //find count of elements smaller than/equal to mid
        for (int i = 0; i < matrix.size(); i++)
            place += upper_bound(matrix[i].begin() , matrix[i].end() , mid) - matrix[i].begin();    
        if (place < desired) mini = mid + 1 ;
        else maxi = mid;
}
    // cout << maxi << endl;
    return mini;
}
int main(){
    cout << endl;
    
     vector<vector<int>> matrix1 = {{1, 3, 5},
                                    {2, 6, 9},
                                    {3, 6, 9}};
     cout << upper_bound_method(matrix1) << endl;

    cout << endl;
    return 0;
}
