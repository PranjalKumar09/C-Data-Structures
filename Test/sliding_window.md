### **Sliding Window Technique Notes**

#### **When to Use Sliding Window**  
**Contiguous subarray or substring** & requires optimization or checking certain conditions.  

- \(O(n^2)\) to  \(O(n)\).

---

#### **Common Cases for Sliding Window**

1. **Fixed-Size Window**:

2. **Dynamic-Size Window**:
   - **Use Case**: Find the smallest/largest subarray/substring that satisfies a condition.
   - **Example**: Smallest subarray with sum >= `S`.
   - **Approach**:
     - Expand the window by moving the right pointer until the condition is met.
     - Shrink the window by moving the left pointer while maintaining the condition.
   - **Complexity**: \(O(n)\).  

3. **Substring Problems**:
   - **Use Case**: Check or optimize a substring based on specific criteria (frequency, uniqueness, etc.).
   - **Example**: Longest substring with at most `k` distinct characters.
   - **Approach**:
     - Use a map to count the frequency of characters in the current window.
     - Expand and shrink the window to maintain the condition.
   - **Complexity**: \(O(n)\) for most problems using hashmaps.

4. **Two Ends, Single Window (Double-Sided Sliding Window)**:
   - **Use Case**: Take elements from both ends, exclude middle sections.
   - **Example**: Minimum removals to meet specific criteria from both ends.
   - **Approach**:
     - Use a window to exclude a portion of the array (middle) and evaluate the remaining parts.
   - **Complexity**: \(O(n)\).
   - In this case we like we have to limit frequency from left and right to by first calculating througn all then do reverse while chiching & traversing , 

- ###### **Steps**:
   - 1. **Compute Total Frequencies or Initial Values**:
        - Calculate the **total count or sum** of the elements across the input to know the "global state."

    - 2. **Forward Pass**:
            - Expand the **excluded middle window** by moving the `right` pointer.
            - Keep track of the elements in the excluded portion (e.g., their frequencies or sums).
            - Check whether the **remaining elements** in the left and right portions satisfy the condition.

    - 3. **Reverse Pass (Shrink Left)**:
            - After expanding, move the `left` pointer inward to shrink the excluded window.
            - Dynamically adjust the remaining portions on the left and right, ensuring they still meet the constraints.



#### **How Sliding Window Works**

1. **Single Window**:
   - Start with an empty window `[left, right)`.
   - Expand by increasing `right`.
   - Shrink by increasing `left` when the condition is met.
   - Example for smallest subarray:
     ```cpp
     while (right < n) {
         sum += arr[right++];
         while (sum >= target) {
             minLength = min(minLength, right - left);
             sum -= arr[left++];
         }
     }
     ```

2. **Double Sliding Window**:
   - Represents two ends (`left`, `right`) and excludes a middle portion.
   - Expand both ends until conditions are met, and then slide as needed.
   - Example for middle exclusion:
     ```cpp
     int left = 0, right = n - 1;
     while (left <= right) {
         if (condition_met()) {
             update_result();
         } else {
             shrink_one_end();
         }
     }
     ```

---

#### **Other Variations**

1. **Circular Sliding Window**:
   - Used when the array is treated as circular (e.g., rotating queues).
   - Example: Maximum in a sliding window of size `k` in a circular array.
   - Adjust indices modulo \( n \) to simulate circular behavior.

2. **Multiple Sliding Windows**:
   - Manage two independent sliding windows on the same array.
   - Use Case: Two disjoint subarrays meeting different conditions.


#### **When NOT to Use Sliding Window**
- Non-contiguous subarray problems.
- Problems requiring global information instead of local checks (e.g., sorting).

---

