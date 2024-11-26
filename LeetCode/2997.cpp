#include <bits/stdc++.h>
using namespace std;  
class Solution {
public:
// tc = O(N)    sc = O(1)

    int minOperations(vector<int>& nums, int k) {
        int finalXor = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

        cout << xorArray << endl;
        int count = 0;        
        while (k || finalXor) {
            // k % 2 returns the rightmost bit in k,
            // finalXor % 2 returns the rightmost bit in finalXor.
            // Increment counter, if the bits don't match.
            if ((k % 2) != (finalXor % 2)) 
                count++;
            
            
            // Remove the last bit from both integers.
            k /= 2;
            finalXor /= 2;
        }
        
    return count;
    }
};
int main(){
    vector<int> nums  = {2,1,3,4} ;
     int k  = 1;

    Solution s;
    cout << s.minOperations(nums , k) <<  endl;


    return 0;
}