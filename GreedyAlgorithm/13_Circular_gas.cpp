#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int totalFuel = 0, currFuel = 0, start = 0;
        
        for (int i = 0; i < n; i++) {
            int balance = gas[i] - cost[i];
            totalFuel += balance;
            currFuel += balance;

            // If fuel goes negative, reset start point
            if (currFuel < 0) {
                start = i + 1;
                currFuel = 0;  // Reset fuel
            }
        }
        
        // If total fuel is negative, circuit is impossible
        return (totalFuel >= 0) ? start : -1;
    }
};

// Driver function (main)
int main() {
    Solution sol;
    
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    
    int result = sol.startStation(gas, cost);
    
    if (result == -1) {
        cout << "Circuit completion is impossible!" << endl;
    } else {
        cout << "Start at gas station index: " << result << endl;
    }
    
    return 0;
}
