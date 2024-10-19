#include <bits/stdc++.h>
using namespace std;

/* 
Conditional  Sum
================
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, result, combination, 0);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combination, int start) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) break; // Early stopping condition
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, combination, i); // Not i + 1 because we can reuse the same element
            combination.pop_back();
        }
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = solution.combinationSum(candidates, target);
    for (auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
