/* Note: in loop condtion of (arr[j] != arr[i]) then{ j++; 
        arr[j] = arr[i];    }
also  
size => j+1
because j is starting from 0 so + 1 to correct it 
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;


void display(vector<int> &arr){
    cout << endl << "{ ";
    int size = arr.size();
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " }";
}

vector<int> setMethod_remove_dupicate(vector<int> &arr){
    set<int> temp;
    vector<int> result;
    for(int i = 0; i < arr.size(); i++) temp.insert(arr[i]);
    for (auto i : temp) result.push_back(i);
    return result;
}

vector<int> double_pointer_remove_dupicate(vector<int> &arr){
    sort(arr.begin(), arr.end());
    int j = 0;
    for (int i = 1 ; i < arr.size(); i++){
        if (arr[j] != arr[i]) {j++; 
        arr[j] = arr[i];       } 
    }
    vector <int> result(j+1); 
    for (int i = 0; i < j+1  ; i++) result[i] = arr[i];
    return result;
}


int main(){
    cout << endl;

    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};

    //method 1 
    // vector<int> result = setMethod_remove_dupicate(arr);
    // display(result);

    //method 2 
    vector<int> result  = double_pointer_remove_dupicate(arr);
    display(result); 




    cout << endl;

    return 0;
}