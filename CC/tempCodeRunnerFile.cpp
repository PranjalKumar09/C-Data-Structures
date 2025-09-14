class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) return   findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n-1;

        while(l <= r){
            int px = l + (r-l)/2;
            int py = (m+n+1)/2 - px;
            
            int x1 = (px == 0)? INT_MIN: nums1[px-1];
            int x3 = (py == 0)? INT_MIN: nums2[py-1];

            
            
            int x2 = (px == m)? INT_MAX: nums1[px];
            int x4 = (py == n)? INT_MAX: nums2[py];

            if (x1 <= x4 && x2 <= x3){
                if ((m+2)%2) return max(x1,x3);
                return (max(x1,x3)*1.0+min(x2, x4)*1.0)/2;
            }
            if (x1 > x4) r= mid+1;
            else l = mid-1;
        }
        return -1;
    }
};