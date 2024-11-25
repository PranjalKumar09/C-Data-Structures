#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:

    bool check(vector<int> nums, int x){
        x*=(-1);
        for (int i = 0; i < nums.size(); i++) 
            if (nums[i] == x) return true;
        return false;

    }
    int findMaxK(vector<int>& nums) {
        int ans = -1;

        for (int i = 0; i < nums.size(); i++) 
            if (nums[i] > 0 && check(nums, nums[i])) ans = max(ans, nums[i]);
        return ans;
    }

};

class Solution2
{
public:
    int findMaxK(vector<int>& nums) 
    { // better solution 2 
        sort(nums.begin(), nums.end());
        int low=0, high=nums.size()-1;
        
        while(low < high)class Solution 
{
public:
    int findMaxK(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int low=0, high=nums.size()-1;
        
        while(low < high)
        {
            if((nums[low] + nums[high]) == 0)
            {
                return  nums[high];
            }
            
            else if((nums[low] + nums[high]) < 0)
                low++;
            
            else high--;
        }
        return -1;
    }
};
        {
            if((nums[low] + nums[high]) == 0)
            {
                return  nums[high];
            }
            
            else if((nums[low] + nums[high]) < 0)
                low++;
            
            else high--;
        }
        return -1;
    }
};

int main(){


    Solution s;
    vector<int> nums = {-1,2,-3,3};
    cout << s.findMaxK(nums);

}