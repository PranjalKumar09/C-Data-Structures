class Solution {
public:
    bool solve(int mid, int n, int index, int maxSum){
        int maxiSum = mid*n;
        
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 1;
        int r = maxSum;
        
        while (l < r){
            int mid = l + (r-l)/2;
            
            if (solve(mid, n, index, maxSum)){
                l = mid;
            }
            else r = mid-1;
        }
        return l;
    }
};