#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthMissing(vector<int> &arr, int k)
{

    int missingCount = 0; // Number of missing numbers found so far
    int previous = 0;     // We can consider 0 as the number before the first element

    for (int i = 0; i < arr.size(); ++i)
    {
        int current = arr[i];

        // Number of missing numbers between previous and current
        missingCount += current - previous - 1;

        // If missingCount >= k, it means the kth missing number is between previous and current
        if (missingCount >= k)
            return current - (missingCount - k) - 1;

        previous = current; // Update previous to the current number
    }

    // If we haven't found the kth missing number in the array, it lies beyond the last element
    return arr.back() + (k - missingCount);
}

int main(){
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 4;

    cout << "The " << k << "th missing number is: " << kthMissing(arr, k) << endl;

    return 0;
}