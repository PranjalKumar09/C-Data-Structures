#include <bits/stdc++.h>
using namespace std;

/* 
brute force
-> take only takeable values




 */

#include <bits/stdc++.h>


/* 
    make all subsets 
    & find out good subsets ->







 */




class Solution1 { // mine 1st code giving tle
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        sort(nums.begin()  , nums.end());
        for (int i = 1 ; i < (1<<nums.size()) ; i++){ // from 1 because first subset will void
            vector<int> subsets;
            for (int j = 0; j<nums.size() ; j++)
                if ((1<<j)&i) subsets.push_back(nums[j]);
            bool checker = 0 ;
            


            for (int j = 0; j<subsets.size()-1 && !checker; j++){
                for (int m = j+1 ; m<subsets.size() ; m++ ){
                    if (subsets[m] - subsets[j] == k) {
                        checker = 1;
                        break ;
                    }
                    if (subsets[m]-subsets[j] > k) break;
                }
            }
            if (!checker ) count ++;
           }
        return count;
                        
    }
};






int main(){
    cout << " hello " << endl;
}