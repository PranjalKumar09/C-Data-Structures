#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 
FIRST -VE (NEGATIVE) IN EVERY WINDOW OF K 
==========================================
                  _________________
    ______________|_______________|___->_____
    |   |   |   | | |   |   |   | | |   |   |
    |   |   |   <=| |   |   |   | |<=   |   |
    |___|___|___|_|_______________|_|___|___|
                  |_______________|   ->
    

    answer = d.front()  or  0
    d.front => store -ve element indexes 
    0 => if no negative element

 */

vector<int> solve(vector <int> &arr , int  k){
    queue<int> dq;
    vector <int> ans ;

    for (int  i = 0; i < k ; i++)
        if (arr[i] < 0) dq.push(i);
    ans.push_back(dq.empty()? 0 : arr[dq.front()]);
    for (int i = k ; i < arr.size() ; i++){
        if (!dq.empty() && i- dq.front() >= k) dq.pop();
        if (arr[i] < 0) dq.push(i);
        ans.push_back(dq.empty()? 0 : arr[dq.front()]);
    }
    return ans;
    
}
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, 15, 30, -16, 28};
    int k = 3;
    
    vector<int> result = solve(arr, k);
    
    cout << "The first negative number in every window of size " << k << " is: ";
    printArray(result);
    
    return 0;}