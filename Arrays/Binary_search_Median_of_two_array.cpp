/* 

Let n ber size of array1 and m be size of array2 
We will divide two array in two equal parts  (n+m)/2
we will make left part and right part
for this we have to cpick starting  n / 2  from array1 and m / 2 from array2 too make left part for this will pick n /2 from array1 and (n+m)/2  - n/2 from array2 
now left element will be in right part 

l1 = the maximum element belonging to arr1[] of the left half.
l2 = the maximum element belonging to arr2[] of the left half.
r1 = the minimum element belonging to arr1[] of the right half.
r1 = the minimum element belonging to arr2[] of the right half.



l1 > r2 => high = mid -1

l2 > r1 => low = mid + 1




so median will (max(l1,l2) + min(r1,r2) ) / 2

 


we need to do BS in shorter array 




Time Complexity: O(log(min(n1,n2))), where n1 and n2 are the sizes of two given arrays.
Reason: We are applying binary search on the range [0, min(n1, n2)].

Space Complexity: O(1) as no extra space is used.

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;



double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return median(b, a);

    //this means a will always smaller or equal NEVER graeter




    int n = n1 + n2; //total length
    int left = (n1 + n2 + 1) / 2; //length of left half
    //apply binary search:
    int low = 0, high = n1;  // running for smaller loop for better TC
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN; // maximum element from both arrays from left side
        int r1 = INT_MAX, r2 = INT_MAX; // minimum element from both arrays from right side
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) { // it means partiition should be like that such that maximum element from both array from left side should be smaller than  or equal to right side
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;

        // what this is doing deving the array 
        // like taking first comlpete smaller array then half of smaller array it can either left or right porition as this same thing continurs



    }
    return 0; //dummy statement
}





/* 
DRY RUN 

array 1 =>> [7 12 14 15]
array 2 =>> [1 2 3 4 9 11]

combination look like [1 2 3 4 7 | 9 11 12 14 15]

You can pick from 0 to 4 from array 1 
0       2       4
low     mid     high
Picking 2 element from array1 , 3 from array2 =>  [  1 2 3 7 12 |  4  0 11  14 15 ]
so l1 = 12 , r2 = 7 =>   l1 >  r2  =>    12 >  7 => high = mid - 1 => high  =  1

0        0        1
low     mid    high

Pikcing 0 from array 1 , 5 from array2 => [1 2 3 4 9 |   7 11  12 14 15 ]
l1 = 0 , r2  = 11
l1 > r2 =>  0 > 11     NO     so  ,,  low = mid + 1 => low = 1

1        1      1
low     mid    high

Picking 1 from array 1 , 4 from array2 => [1 2 3 4 7 | 9 11 12 14 15]

Now do 
 */






int main(){
    cout << endl;

    vector<int> arr1 = {2,4,6}, arr2  = {1,3,5}; 
    cout << median(arr1, arr2) << endl;

    







    cout << endl;
    return 0;
}