/* Aggressive Cows : {MINIMUM DISTANCE B/W COW} IS MAX
Problem Statement: You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
You are also given an integer ‘k’ which denotes the number of aggressive cows.
You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.

SOLUTION
1) Sort the array
2) then go



 */
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// Function to check if it's possible to place cows with a minimum distance
// Parameters:
//   - stalls: Vector representing the distances between stalls (sorted)
//   - minDist: The current minimum distance required between cows
//   - k: Total number of cows to be placed
// Returns:
//   - True if it's possible to place cows with the given minimum distance, false otherwise
bool isPossible(vector<int> &stalls, int minDist, int k)
{
    int cows = 1;               // Placed cow at the first available slot i.e stalls[0] (Greedy)
    int lastCowPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        // If the distance between the current stall and the last placed cow is greater than or equal to minDist
        if (stalls[i] - lastCowPosition >= minDist)
        {
            cows++;                  // Place a cow at the current stall

            if (cows >= k) return true;  // If we have placed enough cows, return true

            lastCowPosition = stalls[i];  // Update the last placed cow's position to the current stall
        }
    }
    return false;  // If the loop completes, it means it's not possible to place cows with the required minimum distance
}


// Function to find the maximum minimum distance between any two cows
// Parameters:
//   - stalls: Vector representing the distances between stalls (sorted in ascending order)
//   - k: Total number of cows to be placed
// Returns:
//   - The maximum minimum distance between any two cows
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());  // Sorting the stalls in ascending order
    
    int low = 1;                          // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    
    int res;  // Result variable to store the maximum minimum distance
    
    while (low <= high)
    {
        int mid = (low + high) / 2;  // Calculate the mid-point
        
        if (isPossible(stalls, mid, k))
        {
       // Update result if placing cows is possible with the current minimum distance
            low = mid + 1;     // Move the low pointer to the right to explore larger distances
        }
        else
            high = mid - 1;    // Move the high pointer to the left to explore smaller distances
        
    }
    
    return res;
}



int main(){
    cout << endl;
    
    int N = 6, k = 4;
    vector<int> arr = {0,3,4,7,9,10};
    // display(arr, N);
    cout << aggressiveCows(arr,  k);
    

    cout << endl;
    return 0;
}
