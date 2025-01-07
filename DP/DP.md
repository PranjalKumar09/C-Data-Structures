
### **Dynamic Programming (DP) Concepts:**

1. **Tabulation (Bottom-Up)**:
   - Solve subproblems iteratively and build up the solution.

2. **Memoization (Top-Down)**:
   - Solve problems recursively and store the results to avoid redundant calculations.

### **General DP Strategy:**
1. **When to Apply Recursion**:  
   - Use recursion for problems like "try all possible ways", "count", or "find the best way".
  
2. **Representing Problems with Indices**:
   - Always use indices, even if not directly an array. For problems like summing or counting ways:
     - Sum all stuff → "count all ways".
     - Minimize → "find the minimum".

3. **Edge Cases**:  
   - Think of base cases and boundaries (e.g., 0 or 1).

4. **In Loops**:
   - In DP loops, consider starting the loop from 1 and minimizing or maximizing calculations with fewer iterations if possible.

### **Memoization & Tabulation Comparison:**

1. **Memoization**:  
   - Top-down approach, store results of subproblems to avoid recomputation. 
   - Time Complexity (TC) and Space Complexity (SC): Depends on recursion depth and storage.

2. **Tabulation**:  
   - Bottom-up approach, iteratively fill the DP table.
   - Time Complexity (TC) and Space Complexity (SC): Generally more efficient in terms of space.

3. **Space Optimization**:  
   - Reduce space usage by storing only necessary results (e.g., only the last few results in some problems).

### **Example: Fibonacci Series**

**Memoization**:
```cpp
int f(int n, vector<int>& dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}
```
**Space Optimized Version** :

```cpp 
int prev2 = 0,
            prev = 1;
for (int n = 2; n <= N; n++)
{
    int cur = prev2 + prev;
    prev2 = prev;
    prev = cur;
}
cout << prev;
```
**Time Complexity** : O(n),
**Space Complexity** : O(1)

                                                       -- -

                               ## #**Staircase Problem(Climbing Stairs) * * :

    -**Recursion ** :
  ```cpp
    int f(int n)
{
    if (n == 0)
        return 1;
    return f(n - 1) + f(n - 2);
}
```

    - **Space Optimized ** :
  ```cpp int prev2 = 0,
              prev = 1;
for (int i = 2; i <= n; i++)
{
    int cur = prev2 + prev;
    prev2 = prev;
    prev = cur;
}
cout << prev;
```
**Time Complexity** : O(n),
**Space Complexity** : O(1)
-- -
### **Space Optimization Tips** :

1. **Avoid Storing Entire DP Table** : -For problems like Fibonacci
or climbing stairs,
only keep track of the last few results(e.g., two previous values).

2. **Optimize Recursion** : -Convert recursive solutions to iterative ones where possible(e.g., dynamic programming solutions).
