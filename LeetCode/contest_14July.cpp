#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        int i = 1, j = 1, ans = 0;
        while(i<=m && j <= n){
            cout << "running"<< endl;
            if (j*horizontalCut[i-1] > i*verticalCut[j-1]){
                ans += i*verticalCut[j-1];j++;}
            else {
                ans+= j*horizontalCut[i-1];i++;}
        }
        while(i<=m){
             ans+= j*horizontalCut[i-1];i++;}
        while(j<=m){
            ans+= i*verticalCut[j-1];j++;}
        return ans;
    }
};

int main() {
    Solution sol;
    int m = 5, n = 4;
    vector<int> horizontalCut = {1, 2, 4, 5};
    vector<int> verticalCut = {1, 3, 4};
    cout << sol.minimumCost(m, n, horizontalCut, verticalCut) << endl;
    return 0;
}