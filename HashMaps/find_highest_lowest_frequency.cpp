#include <bits/stdc++.h>
using namespace std;

/* 
FIND HIGHEST LOWEST FREQUENCY ELEMENT
=====================================
    TC = O(n)
    SC = O(n)
 */

vector<int> solve(vector<int> &arr){
    map<int, int> mp;
    for (auto i: arr) mp[i]++;


    vector<int> ans = {0 ,INT_MAX, 0 , 0};
    int &maxFreq = ans[0];
    int &minFreq = ans[1];
    int &maxElement = ans[2];
    int &minElement = ans[3];
    
    for (auto i: mp){
        int freq = i.second;
        int element = i.first;
        if (freq > maxFreq) {
            maxFreq = freq;
            maxElement = element;
        }
        if (freq < minFreq) {
            minFreq = freq;
            minElement = element;
        }
    }
    return ans;
}
int main(){
     vector<int> arr = {1, 3, 1, 4, 3, 2, 1, 3, 4, 3, 5, 5, 5, 5};
    vector<int> result = solve(arr);
    
    cout << "Max Frequency: " << result[0] << ", Element: " << result[2] << endl;
    cout << "Min Frequency: " << result[1] << ", Element: " << result[3] << endl;
    
    return 0;
}
