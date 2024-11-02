#include <bits/stdc++.h>
using namespace std;

/*  
Hand of Straights
================= 
    Not done by Heaps
    
    i/p: arr , k (int groupSize)
    is it possible to divide in k groups size in which elements should consecutive

    o/p: boolean

    1 2 3     4 5 6    True
    1 3 4     2 5 6    False

    {1,2,3,6,2,3,4,7,8} => {1,2,2,3,3,4,6,7,8} => {1,2,3} , {2,3,4} , {6,7,8} True

    its better to do this from map way than heap pq , because in map it is easy and optimzed
*/
bool solve(vector<int> &hand, int W) {
    if (hand.size()%W) return 0;
    map<int, int> mp;
    for (auto i: hand ) mp[i]++;
    while (!mp.empty()){
        int curr = mp.begin()->first;
        for (int i = 0 ; i < W ; i++){
            if (mp[curr+i] == 0) return false;
            mp[curr+i]--;
            if (mp[curr+i] < 1) mp.erase(curr+i);
        }
    }   
    return true;
    }




int main() {
    vector<int> arr1 = {1,2,3,6,2,3,4,7,8};
    int k1 = 3;
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int k2 = 4;
    vector<int> arr3  = {1,1,2,2,3,3};
    int k3 = 3;

    // Test solve
    bool result_1 = solve(arr1, k1);
    bool result_2 = solve(arr2, k2);
    bool result_3 = solve(arr3, k3);
    cout << "Test Case 1: " << (result_1 ? "True" : "False") << endl;
    cout << "Test Case 2: " << (result_2 ? "True" : "False") << endl;
    cout << "Test Case 3: " << (result_3 ? "True" : "False") << endl;


    return 0;
}


