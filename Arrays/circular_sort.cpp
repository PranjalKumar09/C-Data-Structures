#include <iostream>
#include <vector>
using namespace std;

/* 
In question given array contain positive no & negative no and we have to find smallest missing positive no


 */

int findSmallestMissingPositive(vector<int> &arr)
{
    int n = arr.size();

    // Step 1: Place elements in their correct positions
    for (int i = 0; i < n; i++)
    {
        // While arr[i] is in the valid range [1, n] and not at the correct index
        while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
        {
            // Swap arr[i] with arr[arr[i] - 1] to place arr[i] at the correct index
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    // Step 2: Find the first missing positive number
    for (int i = 0; i < n; i++)
    {
        // If arr[i] is not i + 1, then i + 1 is the smallest missing positive
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }

    // If all numbers are placed correctly, then the missing number is n + 1
    return n + 1;
}

int main()
{
    // Test example
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << "Smallest missing positive number: " << findSmallestMissingPositive(arr) << endl;
    return 0;
}
