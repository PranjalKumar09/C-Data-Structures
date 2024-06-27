/* 

BruteForce ->
Time Complexity: O(N^2)
Space Complexity: O(1)




Optimized ->
TC: O(NlogN) + O(N), N = size of the given array.
SC : O(1)



Optimized -> 
TC:  O(N) + O(2*N) ~ O(3*N), where N = size of the array.
Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).

SC : O(N),







 */









#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>

using namespace std; 



bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int BruteForce(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int better(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    int length = 1, maxi = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1] + 1)
            length++;
        else {
            maxi = max(maxi, length);
            length = 1;
        }
    }

    // Update maxi after the loop
    maxi = max(maxi, length);

    return maxi;
}

int longestSuccessiveElements(vector<int>& array) {
    int size = array.size();
    if (size == 0) return 0;

    int longestSequenceLength = 1;
    unordered_set<int> uniqueNumbers;

    // Put all the array elements into set:
    for (int i = 0; i < size; i++) 
        uniqueNumbers.insert(array[i]);
    

    // Find the longest sequence:
    for (auto currentNumber : uniqueNumbers) {
        // cout << "current number = "  << currentNumber << endl;
        // If 'currentNumber' is a starting number:
        if (uniqueNumbers.find(currentNumber - 1) == uniqueNumbers.end()) { // this if checking if current number is lowerst in sequence or not , this way it takes (2*N) max in this loop
            // cout << "Entered inside if when current number is " << currentNumber << endl;
            // Find consecutive numbers:
            int currentSequenceLength = 1;
            int nextNumber = currentNumber;
            while (uniqueNumbers.find(nextNumber + 1) != uniqueNumbers.end()) {
                nextNumber = nextNumber + 1;
                currentSequenceLength = currentSequenceLength + 1;
            }
            longestSequenceLength = max(longestSequenceLength, currentSequenceLength);
        }
    }
    return longestSequenceLength;
}




int main(){
    cout << endl;

    vector<int>  arr =  {100, 200, 1, 3, 2 , 4};
    int  H = 5;
    cout << longestSuccessiveElements(arr) ;
    

    cout << endl;
    return 0;
}