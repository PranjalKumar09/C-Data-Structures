/*


  */

#include <bits/stdc++.h>
using namespace std;


/* 
a b a

    outter for loop 0
        xor_value = 1
        inner for loop 0
            mask = 1
            xor_value^mask = 0
            ans = 1
        inner for loop 1
            mask = 2
            xor_value^mask = 0
            ans = 1
        inner for loop 2
            mask = 4
            xor_value^mask = 0
            ans = 1
        inner for loop 3
            mask = 8
            xor_value^mask = 0
            ans = 1
        inner for loop 4
            mask = 16
            xor_value^mask = 0
            ans = 1
        inner for loop 5
            mask = 24
            xor_value^mask = 0
            ans = 6
        inner for loop 6
            mask = 32
            xor_value^mask = 0
            ans = 1
        inner for loop 7
            mask = 64
            xor_value^mask = 0
            ans = 1
        inner for loop 8
            mask = 128
            xor_value^mask = 0
            ans = 1
        inner for loop 9
            mask = 512
            xor_value^mask = 0
            ans = 1

       
 */



class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> arr = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
        long long ans = 0;
        unordered_map<int, int> count;
        count[0] = 1;
        int xor_value = 0;
        for (int i = 0; i < word.length(); i++) {
            xor_value ^= 1 << (word[i] - 'a');
            for (int j = 0; j < 10; j++) {
                int mask = 1 << j; // odd no of cases 
                ans += count[xor_value ^ mask]; // checking invidual
            }
            ans += count[xor_value]; // cumulative sum
            // this is for even no of cases 


            count[xor_value]++; // increasing the count of each element
        }
        return ans;
    }

    
};

class Solution2 { // this is better solution logic of both same 
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<ll, ll> mp;

        mp[0] = 1;
        int cum_xor = 0;

        ll result = 0;


        for(char &ch : word) {

            int shift = ch - 'a';

            cum_xor ^= (1 << shift);

            result += mp[cum_xor];

            for(char ch1 = 'a' ; ch1 <= 'j'; ch1++) {
                shift = ch1 - 'a';

                ll check_xor = (cum_xor ^ (1 << shift));

                result += mp[check_xor];
            }

            mp[cum_xor]++;

        }

        return result;
    }
};
int main() {
    Solution s;
    cout << "aba " << s.wonderfulSubstrings("aba") << endl; // Output: 4
    cout << "aabb " << s.wonderfulSubstrings("aabb") << endl; // Output: 9
    cout << "he " << s.wonderfulSubstrings("he") << endl; // Output: 2
    cout << "leetcode " << s.wonderfulSubstrings("leetcode") << endl; // Output: 55
    
    return 0;
}
