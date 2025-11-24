Below is a **fully rebuilt, polished, unified, expanded, and clean** version of your **Greedy Algorithm Notes**.
All content is merged, reorganized, clarified, and stylistically consistent.

---

# **Greedy Algorithm Notes**

## **Core Principles**

1. **Make locally optimal choices** that move toward a global optimum.
2. **No backtracking** — once a choice is made, it stays.
3. **Greedy choice property** — a local optimum is part of a global optimum.
4. **Optimal substructure** — optimal solutions contain optimal sub-solutions.

---

## **Common Patterns**

### **1. Sorting-Based Greedy**

Often the first strategy to try.

```cpp
sort(arr.begin(), arr.end());
for (int i = 0; i < n; i++) {
    // Greedy choice on sorted data
}
```

### **2. Two Pointers**

Useful for pairing, matching, or dual-end processing.

```cpp
int L = 0, R = n-1;
while (L <= R) {
    if (condition) L++;
    else R--;
}
```

### **3. Priority Queue (Heap)**

Pick the largest/smallest element repeatedly.

```cpp
priority_queue<int> pq;
for (int x : nums) pq.push(x);
while (!pq.empty()) {
    int top = pq.top();
    pq.pop();
}
```

---

## **Important Problems & Patterns**

---

### **Interval Scheduling (Maximum Non-overlapping Intervals)**

Greedy rule: **pick the earliest finishing interval**.

```cpp
sort(intervals.begin(), intervals.end(),
     [](auto &a, auto &b){ return a[1] < b[1]; });

int end = intervals[0][1], count = 1;
for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] >= end) {
        count++;
        end = intervals[i][1];
    }
}
```

---

### **Event Selection Problem**

Same pattern as interval scheduling:
**Sort by end time → select max non-overlapping events.**

---

### **Tasks and Deadlines (Scheduling to Maximize Score)**

Score = `deadline - completion_time`.

* Sort tasks by **duration ascending** (shortest processing time first).
* Swapping long-before-short always reduces total score → proves greedy.

---

### **Coin Change (When Greedy Works)**

Works only for **canonical coin systems** (e.g., US coins).

```cpp
vector<int> coins = {1,5,10,25};
int amount = 67, count = 0;

for (int i = coins.size()-1; i >= 0; i--) {
    count += amount / coins[i];
    amount %= coins[i];
}
```

---

## **Problem-Specific Insights**

---

### **948. Bag of Tokens**

* Sort tokens.
* Use two pointers:

  * Spend smallest tokens to gain score.
  * Sell largest tokens to regain power when needed.

---

### **881. Boats to Save People**

Classic two-pointer pairing.

```cpp
sort(people.begin(), people.end());
int L = 0, R = people.size()-1, boats = 0;

while (L <= R) {
    if (people[L] + people[R] <= limit) L++;
    R--;
    boats++;
}
```

---

### **1328. Break a Palindrome**

* Change first non-`'a'` to `'a'`.
* If all `'a'`, change last char to `'b'`.
* If length = 1 → impossible → return `""`.

---

### **991. Broken Calculator**

Reverse process:

* If target > start:

  * even → divide by 2
  * odd → +1
* If target < start: only option = subtract 1 repeatedly.

---

### **1578. Minimum Time to Make Rope Colorful**

Track previous max in a color segment.

```cpp
int prev = neededTime[0], time = 0;
for (int i = 1; i < n; i++) {
    if (colors[i] != colors[i-1]) prev = 0;
    time += min(prev, neededTime[i]);
    prev = max(prev, neededTime[i]);
}
```

---

### **2136. Earliest Full Bloom**

* Sort seeds by **grow time descending**.
* Plant long growers first to minimize delay.

---

### **2131. Longest Palindrome from Two-Letter Words**

**Core idea**

* Count frequencies of each word.
* For non-palindromes (`"ab"` vs `"ba"`): match pairs → add `4` per pair.
* For palindromes (`"aa"`):

  * `cnt/2` pairs → each adds 4
  * At most one leftover can be placed in the center (+2)

**Important:**
Avoid modifying the map while iterating; either iterate on a copy or ensure only one direction is processed (`w < rev`).

---

### **1323. Maximum 69 Number**

Two methods:

1. Convert to string → flip first `'6'` to `'9'`.
2. Math trick → add `3`, `30`, `300`, … at the first `6` digit.

---

### **134. Gas Station**

Greedy logic:

* Track running balance of gas.
* If balance goes negative → restart at next station.
* Valid solution exists only if:
  **total gas ≥ total cost**.

---

### **2366. Minimum Replacements to Sort the Array**

Go from right to left:

* If `nums[i] > nums[i+1]`, split into `parts`:
  [
  parts = \frac{nums[i] + nums[i+1] - 1}{nums[i+1]}
  ]
* Replacements needed = `parts - 1`.

---

### **1326. Minimum Number of Taps to Water a Garden**

Convert taps into intervals:

* Sort by start.
* Greedily extend the farthest reachable coverage (like interval covering).

---

### **Minimum Deletions to Make Character Frequencies Unique**

Strategy:

* Count frequencies.
* Use a set to track used frequencies.
* If duplicate frequency → decrement until unique.

---

### **2038. Remove Colored Pieces if Both Neighbors Are the Same Color**

Key rule:

* Each `"AAA"` gives Alice 1 move.
* Each `"BBB"` gives Bob 1 move.
* Alice wins if `A_moves > B_moves`.

---

## **When to Use Greedy**

### ✅ **Good candidates**

* Optimization problems (min/max)
* Interval-related problems
* Scheduling tasks/events
* Huffman coding
* Minimum spanning tree (Kruskal)
* Coin change (canonical)

### ❌ **Avoid greedy when**

* Future decisions depend heavily on earlier choices
* Backtracking is required
* Overlapping subproblems → use **DP**

---

## **Pro Tips**

1. Always consider **sorting** first.
2. Try **reverse thinking** (e.g., Broken Calculator).
3. Use **two pointers** for pairing or multi-end movement.
4. Track **previous best** values in sequential decisions.
5. In interviews → start with brute force to justify greedy.

---

## **Common Pitfalls**

1. Assuming greedy works without proof.
2. Ignoring edge cases (empty, size=1).
3. Modifying containers while iterating (e.g., maps).
4. Forgetting to sort.
5. Wrong comparator logic.

---

**When in doubt: always prove your greedy choice is optimal.**

---
