#include <bits/c++.h>

//   K-th Smallest Prime Fraction


class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // fraction will like 0 to 1  (0,1)
        
        int n = arr.size();
        double left = arr[0]/(double)arr[n-1], right = 1, mid;
        vector<int> res;

        while (left < right) {
            mid = left + (right - left) / 2;
            int j = 1, total = 0, num = 0, den = 0;
            double maxFrac = 0;

        // ********************************* (like we have to select how many are smaller than mid in fraction)
            for (int i = 0; i < n; ++ i) {
                while (j < n && arr[i] >= arr[j] * mid) ++j; // basically in this loop we are traversing & reaching upto where arr[i]/arr[j] is bigger than previous i
                total += n - j; // arr[i] >= arr[j] * mid
                //  n - j gives you the count of denominators which satisfy the condition, 

                if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i; den = j; // changing numerator and denomartor in this change smaller than this num and den will always smaller 
                }
            }
        // *********************************
            if (total == k) {
                res = {arr[num], arr[den]};
                break;
            }

            if (total > k) 
                right = mid;
             else  //  total < k
                left = mid;
            
        }

        return res;
    }};
int main(){

}
