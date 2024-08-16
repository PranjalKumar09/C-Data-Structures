/* Note:
In both rotate (left,right) by 1 loop runs complete 
in left it runs ascending order and code inside is arr[i] = arr[i+1]
in right it runs descending order and code inside is arr[i] = arr[i-1]
left it stores first element, right it stores last element
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

void Left_Rotate_by_1(vector <int>& arr ){
    int temp = arr[0];
    for (int i = 0; i < arr.size(); i++)
        arr[i] = arr[i+1];
    arr[arr.size()-1] = temp;
}

void Right_Rotate_by_1(vector <int>& arr ){
    int temp = arr[arr.size()-1];
    for (int i = arr.size()-1; i >= 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

int main(){
    cout << endl;

    vector <int> arr = {7, 11, 14, 17, 8, 15, 9, 14, 2, 13};
    display(arr);
    Left_Rotate_by_1(arr);
    display(arr);

    Right_Rotate_by_1(arr);
    display(arr);
    
    
    cout << endl;
    return 0;
}