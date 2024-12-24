#### **Is Array Special**
**Type**: Prefix Array + Query Processing

**Problem**: Check if all subarray elements in the query range have the same parity (odd/even).

**Approach**:
1. **Preprocessing**:
   - Build a prefix array `pre` such that `pre[i]` counts adjacent elements with the same parity up to index `i`.
2. **Query Processing**:
   - For each query range `[l, r]`, check if `pre[l] == pre[r]`. This ensures no parity mismatch in the range.

**Key Steps**:
- Use modular arithmetic (`% 2`) to compare parity of adjacent elements.
- Efficient querying through the precomputed prefix array.

**Code Skeleton**:
```cpp
vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> pre(n, 0);

    // Build prefix array
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1];
        if (nums[i] % 2 == nums[i - 1] % 2)
            pre[i]++;
    }

    // Process queries
    vector<bool> ans;
    for (const auto& it : queries)
        ans.push_back(pre[it[0]] == pre[it[1]]);

    return ans;
}