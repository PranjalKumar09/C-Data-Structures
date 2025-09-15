

### 11. Minimum Cost to Make Array Equal (LeetCode #2448)

* Goal: Make all elements equal, minimizing weighted cost.
* **Cost function:**

  ```cpp
  ll getCost(vector<int>& nums, vector<int>& cost, int target) {
      ll result = 0;
      for (int i = 0; i < nums.size(); i++) {
          result += (ll) abs(nums[i] - target) * cost[i];
      }
      return result;
  }
  ong long minCost(vector<int>& nums, vector<int>& cost) {
    
    ll answer = INT_MAX;
    
    int left = *min_element(nums.begin(), nums.end());  //1
    int right = *max_element(nums.begin(), nums.end()); //5
    
    while (left <= right) {
        int mid = left + (right-left)/2;
        
        ll cost1 = getCost(nums, cost, mid);
        ll cost2 = getCost(nums, cost, mid + 1);
        
        answer = min(cost1, cost2);
        if (cost1 > cost2)
            left = mid + 1;
        else
            right = mid-1;
    }
    return answer == INT_MAX ? 0 : answer;}
  ```
* **Binary search on target value:**

  * Search between `min(nums)` and `max(nums)`.
  * Compare cost at `mid` and `mid+1`.
  * Move towards smaller cost direction.
  * Answer = minimum found cost.

---

### 12. Last Day Where You Can Still Cross (LeetCode #1970)

* Binary search on the day.
* For each mid-day, mark flooded cells, then run **DFS/BFS** from the first row to check if path exists to last row.
* If crossing possible → shift `l = mid+1` and update `ans`.
* Else → reduce `r = mid-1`.


``` cpp
bool solve(vector<vector<int>>& cells, int mid){
    vector<vector<int>> grid(ROW, vector<int>(COL,0));
    for (int i = 0; i <= mid; i++){
        int x=  cells[i][0]-1, y=  cells[i][1]-1;

        grid[x][y] = 1; 
    }

    for (int i = 0; i < COL; i++){
        if (grid[0][i] == 0 && DFS(grid,0, i)) return 1;
    }
    return 0;
}
int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    ROW = row, COL = col;
    int l = 0, r = cells.size() - 1;

    int ans = 0;

    while(l <= r){
        int mid = l+(r-l)/2;
        if (solve(cells, mid)){
            ans = mid+1;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}
```
---

### 13. Peak Index in a Mountain Array

* Binary search on slope:

  ```cpp
  while (l < r) {
      if (arr[mid] < arr[mid+1]) l = mid+1;
      else r = mid;
  }
  ```
* `l` (or `r`) gives peak index.

---

### 14. Minimum Speed to Arrive on Time (LeetCode #1870)

* Interesting condition:

  * Time = sum of `ceil(dist[i]/speed)` except last (no ceil).
  * Binary search on speed.
* Standard template: while `l < r`, check feasibility.

---

### 15. Maximum Running Time of N Computers (LeetCode #2141)

* Key idea: total battery capacity divided across `n` computers.
* Use binary search on possible running time, check feasibility by summing `min(battery, time)` for each.
``` cpp
bool pos(vector<int>& batteries, int n, ll mid){
    ll sum = n*mid;

    for (int i: batteries){
        sum-= min((ll)i, mid);
        if (sum < 1) return 1;
    }   
    return 0;

}
ll maxRunTime(int n, vector<int>& batteries) {
    ll  l = *min_element(begin(batteries), end(batteries)),r = 0;

    for (int i: batteries)
        r+=i;
    r/=n;

    while (l < r){
    ll mid = l+(r-l+1)/2;
    if (pos(batteries, n, mid))
        l = mid;
    else r = mid-1;
    }
    return l;
}
```
---

### 16. Minimize the Maximum Difference of Pairs (LeetCode #2616)

* Sort the array.
* Binary search on maximum allowed difference.
* Check if at least `p` pairs can be formed with difference ≤ mid.
``` cpp
int minimizeMax(vector<int>& nums, int p) {
    if (p == 0) return 0;
    sort(nums.begin(), nums.end());
    int n = nums.size(), left = 0, right = nums[n - 1] - nums[0];

    while (left < right) {
        int mid = left + (right - left) / 2, pairs = 0;
        for (int i = 1; i < n; ++i) {
            if (mid >= nums[i] - nums[i - 1]) {
                ++pairs, ++i;
            }
        }
        if (pairs >= p) right = mid;
        else left = mid + 1;
    }
    return left;
}
```

---

### 17. Median of Two Sorted Arrays

* Total size = `m + n`.
* Binary search on partition in smaller array.
* We can take first array small so it TC is small

* Conditions:

  * Left partition size = `(m+n+1)/2`.
  * Valid partition if:

    ```
    x1 <= x4 and x3 <= x2   
    ```
    ```
    ---- x1 | x2 ----
    ---- x3 | x4 ----
    ```
* Median formula:

  * Odd → `max(x1, x3)`
  * Even → `(max(x1, x3) + min(x2, x4)) / 2`
* Update search:

  * If `x1 > x4` → `h = mid-1`.
  * Else → `l = mid+1`.

---

### 18. Search Target in Mountain Array (LeetCode #1095)

1. Find peak index.
2. Binary search in `[0 ... peak]`.
3. Binary search in `[peak+1 ... n-1]` (decreasing order).

---

### 19. Apply Operations to Maximize Frequency Score (LeetCode #2968)

* Answer must be an element of array.
* Search space: `l = min(array)`, `h = max(array)`.
* Sort array.
* Operations are done between adjacent elements to maximize frequency.

---

### 20. Find the Safest Path in a Grid (LeetCode #2812)

* Precompute safety distances using **multi-source BFS** (from all dangerous cells).
* Then binary search on minimum safety value possible for a path.

BFS template:

```cpp
queue<pair<int, int>> q;
vector<vector<int>> dis(n, vector<int>(n, -1));
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        if (grid[i][j] == 1) {
            q.push({i, j});
            dis[i][j] = 0;
        }

while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
        int ni = i + dir[d][0], nj = j + dir[d][1];
        if (ni >= 0 && nj >= 0 && ni < n && nj < n && dis[ni][nj] == -1) {
            dis[ni][nj] = dis[i][j] + 1;
            q.push({ni, nj});
        }
    }
}
```

---

### 21. Special Array With X Elements Greater or Equal X (LeetCode #1608)

* Check its notes

---

### 22. Minimum Number of Days to Make m Bouquets (LeetCode #1482)

* Binary search on number of days.
* For each mid, check how many bouquets can be formed by grouping consecutive flowers bloomed by that day.
* If enough → shrink range. Else → increase.

```cpp
bool pos(vector<int>& bloomDay, int m, int k,int mid){
    int continuosCount = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++){
        if (bloomDay[i] <= mid) continuosCount++;
        else continuosCount = 0;
        if (continuosCount == k){cnt++;continuosCount=0;
        }
    }
    return cnt >= m;
}
```
---

### 23. General Notes

* Typical binary search mid calculation:

  * `mid = l + (r-l)/2` (when ans in right).
  * `mid = l + (r-l+1)/2` (when ans in low).

---