
### 1. Binary Search Variants

**Finding Leftmost & Rightmost Occurrence**

* When target is matched, store `ans`.
* **Leftmost** → move `right = mid - 1`.
* **Rightmost** → move `left = mid + 1`.
* Range condition uses `<=` (not `<`).

---

### 2. Minimum in Rotated Sorted Array

* Compare with `arr[r]`:

  * If `arr[mid] > arr[r]` → search right (`l = mid + 1`).
  * Else → `r = mid` (not `mid-1`, since `r` itself could be the answer).
* Loop condition → `l < r` (to avoid infinite loop).
* The index of minimum = number of rotations.

---

### 3. Search in Rotated Sorted Array

* Step 1: Find pivot (minimum index).
* Step 2: Binary search separately in:

  * `[0 ... pivot-1]`
  * `[pivot ... n-1]`

**With Duplicates:**

* Skip duplicates before pivot search:

  ```cpp
  while (l < r && arr[l] == arr[l+1]) l++;
  while (l < r && arr[r] == arr[r-1]) r--;
  ```
* Then apply normal pivot logic.

---

### 4. Binary Search in 2D Matrix

* Flattened index: `arr[mid / n][mid % n]`.
* Alternative: Start from **top-right** (`i=0, j=n-1`) and move accordingly.

---

### 5. Single Element in a Sorted Array

* Array example: `[1,1,2,3,3]`.
    Other than `Xor` approach
* Approach:

  * Ensure `mid` is even (if odd, make `mid--`).
  * If `arr[mid] == arr[mid+1]` → unique element in right half (`l = mid + 2`).
  * Else → unique element in left half (`r = mid`).

---

### 6. Guess Number Higher or Lower (LeetCode #374)

* Standard binary search.
* Replace condition check with given API function `guess(num)` returning `-1, 0, 1`.

---

### 7. Kth Missing Positive Number

**Greedy Approach:**

```cpp
int findKthPositive(vector<int>& arr, int k) {
    int num = 1, i = 0, n = arr.size();
    while (i < n && k > 0) {
        if (arr[i] == num) i++;
        else k--;
        num++;
    }
    while (k--) num++;
    return num - 1;
}
```

**Binary Search Approach:**

* Missing count till `arr[i]` = `arr[i] - (i+1)`.
* Use binary search:

  ```cpp
  while (l <= r) {
      int mid = l + (r-l)/2;
      int missing = arr[mid] - (mid+1);
      if (missing < k) l = mid + 1;
      else r = mid - 1;
  }
  return l + k;
  ```

---

### 8. Minimum Time to Complete Trips

* Search space: `l = 1`, `r = min(time) * total_trips`.
* While `l < r`:

  * Compute `mid`.
  * If possible → `r = mid`.
  * Else → `l = mid + 1`.
* Answer = `l` (or `r`).
* **Time Complexity:** `O(log(r) * n)`.

---

### 9. Spells & Potions (Successful Pairs)

* Input: `vector<int> spells, potions`, `int success`.
* Sort both arrays.
* For each spell:

  * Minimum required potion = `ceil(success / spell[i])`.
  * The value then greater or equal to minimumPotion (Use binary search (`lower_bound`) in potions to count valid ones.)

---

### 10. Minimize the Maximum of Array

* Operation: Reduce current element → carry extra to next.
* First element is fixed (cannot be reduced).
* Binary search on `maxValue` (0 → max of array).

**Check function:**

```cpp
for (int i = 0; i < n-1; i++) {
    if (arr[0] > mid) return false;
    int buffer = mid - arr[i];
    arr[i+1] -= buffer;
}
return arr[n-1] <= mid;
```

---

### 11. Maximum Value at a Given Index in a Bounded Array (LeetCode #1802)

* Constraint: The difference between consecutive elements ≤ 1, and all values ≥ 1.
* Idea: Perform binary search on the maximum value at `index`.

  * Use helper function to compute minimal sum required for a given peak value.
  * Check both left and right sides separately.


```cpp
typedef long long ll;

ll getSumElements(ll count, ll val) {
    // Sum of sequence: (val-1) + (val-2) + ... until count terms
    // Equivalent: count*val - (count*(count+1))/2
    return val * count - (count * (count + 1)) / 2;
}
```

**Main Function:**

```cpp
int maxValue(int n, int index, int maxSum) {
    ll l = 1, r = maxSum, result = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;

        ll left_count  = min((ll)index, mid - 1);
        ll left_sum    = getSumElements(left_count, mid) 
                         + max(0LL, index - mid + 1);

        ll right_count = min((ll)n - index - 1, mid - 1);
        ll right_sum   = getSumElements(right_count, mid) 
                         + max(0LL, (ll)n - index - 1 - mid + 1);

        if (left_sum + right_sum + mid <= maxSum) {
            result = max(result, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return result;
}
```

**Key Points:**

* Left sum and right sum are computed based on triangle numbers (`x, x-1, x-2...`) until reaching 1.
* If `mid` is small, extra `1`s are added to fill remaining slots.
* Binary search ensures the largest feasible `mid` is found.

# 

* Condition: Difference between consecutive elements ≤ 1, all elements ≥ 1.
* Use **binary search** on the peak value at `index`.
* For each candidate `x` (mid):

- **Left side:**

  * Minimum possible sum is like a staircase:

    $$
    (x-1), (x-2), (x-3), ... 
    $$

     $$
    left\_sum = left\_count \cdot x - \frac{left\_count \cdot (left\_count + 1)}{2}
    $$

  * If `x` is small, values can’t go below `1`. In that case:

    $$
    1, 2, 3, ... 
    $$

    Extra `1`s are added:

    $$
    no\_of\_ones = left\_count - (x - 1)
    $$

- **Right side:**

  * Same logic as left, with `right_count = n - index - 1`.

- **Check:**

  * If `left_sum + right_sum + x <= maxSum`, then `x` is possible.
  * Else reduce `x`.


