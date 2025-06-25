
# Prefix Sum Summary

## What Is Prefix Sum?

Prefix Sum is a running total of elements in an array.  
It allows you to calculate the sum of any subarray in O(1) time after preprocessing.

---

## When to Use Prefix Sum

- Need to find **sum of subarrays**
- Need to track **running totals**
- Problem asks for **target sums**, especially with subarray boundaries
- Can’t afford O(n²) with nested loops

---

## 🔍 Basic Pattern

### Compute Prefix Sums:
```cpp
vector<int> prefix(n + 1, 0);
for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + nums[i];
}
// sum from i to j = prefix[j+1] - prefix[i]
```

---

## With HashMap (for Target Subarray Sum = k)

```cpp
unordered_map<int, int> seen = {{0, -1}};
int sum = 0, maxLen = 0;

for (int i = 0; i < nums.size(); ++i) {
    sum += nums[i];
    if (seen.count(sum - k))
        maxLen = max(maxLen, i - seen[sum - k]);
    if (!seen.count(sum)) seen[sum] = i; // store first occurrence only
}
```

---

## Use Cases

| Problem Type                          | Use Prefix Sum? |
|--------------------------------------|------------------|
| Subarray sum equals k                | ✅ Yes           |
| Maximum length subarray with sum k   | ✅ Yes           |
| Find average of subarrays            | ✅ Yes (prefix or sliding window) |
| Arbitrary subarray range sum         | ✅ Yes           |

---

## Tips

- Always initialize prefix sum 0 at index -1 when using a hashmap (to capture subarrays starting at index 0)
- Be careful with duplicates — only store first occurrence unless problem says otherwise
- Can be extended to 2D matrices (2D prefix sums)

---

## Common Problems

- Leetcode 560: Subarray Sum Equals K
- Leetcode 325: Maximum Size Subarray Sum Equals k
- Leetcode 974: Subarray Sums Divisible by K
- Prefix sum also appears in range update/query optimizations

---

Prefix sum is **fast, elegant, and a must-know** for any SDE 1 coding interview.
