// Find the Maximum Sum of Node Values | Bit Manipulation | Tree | Graphs
#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0 , cnt = 0 , bakra = INT_MAX;
        for (auto el : nums){
            if ((el^k) > el){
                sum += el^k;
                bakra = min(bakra, (ll)((el^k ) - el)); // whose difference is low 
                cnt ++; // no of times count increase 
            } // bakra is to select the  minimum in case to remove it 
            else {
                sum += el;
                bakra = min(bakra, (ll)el - (el^k));
            }
        }
        if (  cnt%2 == 0) return sum;
        return sum-bakra;}
};