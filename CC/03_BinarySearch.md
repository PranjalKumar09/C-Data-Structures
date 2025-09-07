
Binary Search


finding left most & right most
    When target mathced, store in ans 

    & in left most -> change right
    & in right most -> change left


    * rest same as Binary Search
    * Also as we are searching range is `<=`



Minimum in Rotated Sorted Array
    * Here we compare with arr[r];
        arr[mid] > arr[r] => 
    * else arr[r] = mid; // this is core of question , not mid-1 , but mid, as r is potential anwer

    * so condition is l < r , other wise infinite loop

    and index of minimum is nothing but amount it rotated

Search in Rotated Sorted Array
    Find index of minimum in sorted array (findPivot)
    Then do binary search in two part   (0 -> pivot_idx-1) & (pivot -> size-1)

If Rotated array have duplicate then in same logic have in finding pivot
    while (l < r){
        while(l < r && arr[l] == arr[l+1]) l++;
        while(l < r && arr[r] == arr[r-1]) l--;
        // Same Pivot function
    }



In 2d Matrix
    just remember arr[mid/n][mid%n]


    also in certain case we start from top, right---> j = n-1 => arr[i][j], same


Single Element in a Sorted Array
    1, 1 ,2 , 3 , 3

    other then xor, way, , its given sortted
    we can optimize further

    If mid is odd, make it even (mid -= 1).
    If arr[mid] == arr[mid+1]:

    Single element is in the right half: left = mid + 2.


    Else:

    Single element is in the left half: right = mid.