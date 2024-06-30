/* 
Selection sort minimum no of swap operation 


Selection Sort -> Puts smallest elementt left place (correct place)
TC = O(N^2) , SC = O(1)

 */

#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> &arr){
    cout << endl << "{ ";
    int size = arr.size();
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " }";
}

void Selection_Sort(vector<int> &arr){
    for (int i = 0 ; i < arr.size() ; i++){
        int mini = arr[i];
        for (int j = i + 1 ; j < arr.size() ; j++)  mini = min(mini, arr[j]);
        swap(mini, arr[i]);
    }
}

int main(){
    cout << endl;
     
    vector<int> array4 = {16, 3, 28, 5, 14, 22, 11, 36, 9, 7, 18, 25, 33, 45, 2, 6, 31, 17, 21, 8, 29, 19, 10, 48, 4, 27, 13, 35, 42, 26, 23, 37, 12, 41, 30, 15, 20, 39, 24, 32, 38};

    display(array4);

    Selection_Sort(array4);

    display(array4);

    
    
    cout << endl;
    return 0;
}

