
## What Is Binary Search?

**Binary Search** is a divide-and-conquer algorithm that cuts the search space in half each step. It’s used to search sorted arrays or solve “search on answer space” problems.

---

## When to Use Binary Search

* Array is sorted or monotonic
* You can reframe the problem as a yes/no decision (binary search on answers)
* You need to find min/max value that satisfies a condition

---

## Key Binary Search Patterns (C++)

### Standard Binary Search

```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

### First/Last Occurrence

```cpp
int findFirst(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            if (nums[mid] == target) ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
```

### Binary Search on Answer Space

```cpp
int searchCapacity(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canShip(weights, mid, days)) right = mid;
        else left = mid + 1;
    }
    return left;
}
```

---

## Tips to Remember

* Prevent overflow: use `mid = left + (right - left) / 2`
* Use `left <= right` for standard; `left < right` for answer space
* Watch for infinite loops when updating bounds
* For index return, track `ans` separately if needed

---

## Common Binary Search Problems

| Problem                             | Why Binary Search?                        |
|-------------------------------------|-------------------------------------------|
| Search in Rotated Sorted Array      | Split into sorted halves                  |
| First/Last Position in Sorted Array | Find bounds using variants                |
| Minimum in Rotated Array            | Shrink toward min                         |
| Ship Packages in D Days             | Binary search on weight capacity (answer) |

---

## Binary Search Summary

Use binary search to drastically reduce search time in **sorted** or **monotonic** data. Reframe search problems to exploit binary logic.
