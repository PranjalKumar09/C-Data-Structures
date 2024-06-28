
/* 
Brute Force Method -> 


first loop will run from 0 to arr.size()*2/3 +1 
this optimize because upto ther only element can appear more than n/3 times

count initiliase

second nested loop will run from i+1 to arr.size() 

then check if arr[i] == arr[j] then count++

then if count == arr.size()/3 and (temp size == 0  or arr[current_element] not equal to  last element of temp then push current elelment to temp array and break TOO]]


then check at end of first loop that whether temp size is 2 if then break because after that no further loop will exexcuted 

Time Complexity: O(N2)

Space Complexity: O(1)






Hashing Method->

Time Complexity: O(N*logN)

Space Complexity: O(N) 






OPTIMIZED METHOD (MOORE'S VOTING ALGORITHM)
Time Complexity: O(N) + O(N)
Space Complexity: O(1)

We know that the maximum possible number of elements in the answer is 2.

In this method, four variables are chosen:
- ele1, ele2: to store both potential majority elements (initialized with INT_MIN)
- count1, count2: to count occurrences of the respective elements (initialized with 0)

In the first loop, it iterates through the array:
- If count1 is 0 and ele1 is not equal to the current element, set count1 to 1 and set ele1 to the current element.
- Else if count2 is 0 and ele2 is not equal to the current element, set count2 to 1 and set ele2 to the current element.
- Else if ele1 is equal to the current element, increment count1.
- Else if ele2 is equal to the current element, increment count2.
- If none of the above conditions are met, decrement both count1 and count2.

After the first loop, ele1 and ele2 store the potential majority elements.
Reset count1 and count2 to 0 and re-count the occurrences of ele1 and ele2 by iterating through the array again:
- If the current element is equal to ele1, increment count1.
- Else if the current element is equal to ele2, increment count2.

Finally, check whether the counts of ele1 and ele2 are greater than the threshold (array size divided by 3).
If so, push the respective elements into the result vector.



 */

#include <iostream>
#include <vector> 
using namespace std;

int upper_bound(vector<int> &array , int element){
    int low = 0;
    int high = array.size() - 1 , ans;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if (array[mid] > element)
            {ans = mid ;
            high = mid - 1;}
        else           low = mid+ 1 ;
        }
    return ans;
}





int main(){
    vector<int> arr = {3,5,8,9,15,19};
    int x = 9;
    cout << upper_bound(arr, x );
    
    return 0;
}   