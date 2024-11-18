#include <bits/stdc++.h>
using namespace std;

/* 
1052. Grumpy Bookstore Owner
=============================



 */
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int ans = 0;
    int grumpy_sum = 0;
    int max_grumpy_sum = 0;
    int last = 0;

    for (int i = 0; i < n; i++) {
        if (i - minutes >= 0 && grumpy[i - minutes]) {
            last = customers[i - minutes];
            grumpy_sum -= last;
        }

        if (grumpy[i]) {
            grumpy_sum += customers[i];
            max_grumpy_sum = max(max_grumpy_sum, grumpy_sum);
        } else {
            ans += customers[i];
        }
    }

    return ans + max_grumpy_sum;
}

};


int main(){
    vector<int> customers = {1,0,1,2,1,1,7,5}, grumpy ={ 0,1,0,1,0,1,0,1};
    int minutes = 3;
    Solution s;
    cout << s.maxSatisfied(customers, grumpy, minutes) << endl;

}