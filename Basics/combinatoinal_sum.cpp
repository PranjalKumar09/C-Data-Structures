#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;   
    }
}

void combinational_sum(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ans_element) {
    if (target == 0) {
        ans.push_back(ans_element);
        return;
    }
    
    if (ind >= arr.size() || target < 0)
        return;
    
    if (arr[ind] <= target) {
        ans_element.push_back(arr[ind]);
        combinational_sum(ind, target - arr[ind], arr, ans, ans_element)    ;
        ans_element.pop_back();
    }
    combinational_sum(ind + 1, target, arr, ans, ans_element);
}


void find_combinational_ueque(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ans_element){

    if (target == 0) {
        ans.push_back(ans_element);
        return;
    }
    
    for (int i = ind; i < arr.size(); i++) {
        if ( i > ind && arr[i] == arr[i-1]) continue;
        if (arr[i]>target)break;
        ans_element.push_back(arr[i]);
        find_combinational_ueque(i+1, target - arr[i], arr, ans, ans_element);
        ans_element.pop_back();
    }
}


int main() {
    vector<int> arr = {2, 3, 3, 4, 6, 7};
    int target = 7; 
    vector<vector<int>> ans;
    vector<int> ans_element;
    find_combinational_ueque(0, target, arr, ans, ans_element);

    display(ans);

    return 0;
}
