#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*


    Compute the maximum subarray sum using Kadane's Algorithm.
    Compute the minimum subarray sum using a variation of Kadane's Algorithm.
    Compute the total sum of the array.
    The result is the maximum of:
        Maximum subarray sum from Step 1.
        Total sum minus minimum subarray sum from Step 2.
    Handle the edge case where all elements are negative.
    
    
     */

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &arr)
    {
        int n = arr.size();

        // Step 1: Find the max subarray sum using Kadane's Algorithm
        int maxSum = kadane(arr);

        // Step 2: Find the min subarray sum using Kadane's Algorithm for -arr
        int totalSum = 0, minSum = 0, currentMin = 0;
        for (int num : arr)
        {
            totalSum += num;
            currentMin = min(currentMin + num, num);
            minSum = min(minSum, currentMin);
        }

        // Step 3: Compute max circular subarray sum
        int maxCircularSum = totalSum - minSum;

        // Step 4: Handle edge case where all numbers are negative
        if (maxCircularSum == 0) // all elements are negative
            return maxSum;

        // Step 5: Return the maximum of maxSum and maxCircularSum
        return max(maxSum, maxCircularSum);
    }

private:
    int kadane(vector<int> &arr)
    {
        int maxEndingHere = 0, maxSoFar = INT_MIN;
        for (int num : arr)
        {
            maxEndingHere = max(maxEndingHere + num, num);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};

int main()
{
    Solution sol;
    vector<int> arr1 = {8, -8, 9, -9, 10, -11, 12};
    cout << "Max Circular Subarray Sum: " << sol.maxSubarraySumCircular(arr1) << endl; // Output: 22

    vector<int> arr2 = {10, -3, -4, 7, 6, 5, -4, -1};
    cout << "Max Circular Subarray Sum: " << sol.maxSubarraySumCircular(arr2) << endl; // Output: 23

    vector<int> arr3 = {-1, 40, -14, 7, 6, 5, -4, -1};
    cout << "Max Circular Subarray Sum: " << sol.maxSubarraySumCircular(arr3) << endl; // Output: 52

    return 0;
}
