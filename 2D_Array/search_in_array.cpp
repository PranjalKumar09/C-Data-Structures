#include <iostream>
#include <vector>
using namespace std;

bool search_in_2d_array(vector<vector<int> > &array ,int  num){
    for (int i = 0; i < array.size(); i++){
        for (int j = 0; j < array[i].size(); j++){
            if (array[i][j] == num){
                return true;
            }
        }
    }
    return false;
}

int main(){
    
    vector<vector<int>> arr = { { 3, 12, 9 }, { 5, 2, 89 }, { 90, 45, 22 } };
    cout << search_in_2d_array(arr,22);

}


