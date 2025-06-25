# Sliding Window (C++ Templates)

## Concept

Efficiently analyze contiguous subarrays or substrings without recalculating from scratch.

---

# How to Tell It's a Sliding Window Problem

## Ask Yourself:

- Are you dealing with a **contiguous** segment of an array or string?
- Do you need to **process or maintain** data as this segment **moves**?
- Are you optimizing over **ranges** (min/max/length/sum/frequency)?
- Is performance too slow with brute-force checks for every subarray?

If yes → It's probably a **sliding window**.

---

## Patterns and Clues

| Clue                                        | Implication           |
|---------------------------------------------|------------------------|
| “Contiguous subarray/substring”             | Sliding window likely  |
| “Window of size k”                          | Fixed-size sliding window |
| “At most/exactly k elements”                | Variable-size window   |
| “Find longest/shortest subarray that…”      | Shrinking/growing window |
| “Maintain sum/count/set/map over range”     | Sliding window + hash  |

---

## Common Combinations

| Pattern Combo             | Use Case                                  |
|---------------------------|--------------------------------------------|
| Sliding Window + Hash Set | Uniqueness (e.g., no repeats)             |
| Sliding Window + Hash Map | Frequency constraints (e.g., anagrams)    |
| Sliding Window + Deque    | Max/min in window                         |
| Sliding Window + Counter  | Valid substring tracking (e.g., matches)  |

---

## Not Sliding Window When:

- You’re choosing non-contiguous elements → Use **backtracking**
- Problem is best solved with prefix sums, sorting, or greedy
- You’re picking arbitrary pairs or combinations (not ranges)

---

## Test Cases to Practice

- Leetcode 3: Longest Substring Without Repeating Characters
- Leetcode 76: Minimum Window Substring
- Leetcode 567: Permutation in String
- Leetcode 239: Sliding Window Maximum
- Leetcode 1456: Max Vowels in Substring of Length K


## Types of Sliding Window

### 1. **Fixed-Size Window**
- Window size is constant (e.g. `length = k`)
- Typical use cases: sum, average, max, or count in windows of size `k`

### 2. **Variable-Size Window**
- Window size changes dynamically based on constraints
- Common when finding the longest/shortest subarray satisfying a condition

---

## Key Use Cases

- Maximum/minimum/average in subarrays of size `k`
- Longest substring with/without repeated characters
- Substrings containing a certain number of distinct characters
- Anagrams or pattern matching in a sliding window

---

## Time Complexity

- `O(n)` — each element is added and removed at most once

## Space Complexity

- `O(1)` to `O(k)` — depends on what you store inside the window (set, map, counts, etc.)

---

## Fixed-Size Sliding Window Template

```cpp
int fixedSizeSlidingWindow(string& s, int k) {
    unordered_map<char, int> count;
    int maxResult = 0;

    for (int i = 0; i < s.size(); ++i) {
        count[s[i]]++;

        if (i >= k) {
            count[s[i - k]]--;
            if (count[s[i - k]] == 0) count.erase(s[i - k]);
        }

        if (i >= k - 1) {
            // Update result based on current window
            maxResult = max(maxResult, ...); // insert custom logic
        }
    }

    return maxResult;
}
```
### Variable-Size Sliding Window Template

```cpp
int variableSizeSlidingWindow(string& s) {
    unordered_map<char, int> count;
    int left = 0, result = 0;

    for (int right = 0; right < s.size(); ++right) {
        count[s[right]]++;

        while (/* condition is violated */) {
            count[s[left]]--;
            if (count[s[left]] == 0) count.erase(s[left]);
            left++;
        }

        // Update result based on current window size
        result = max(result, right - left + 1); // or insert custom logic
    }

    return result;
}
```

### Tips to Remember

Use a hash map or set to track characters or frequencies inside the window.

For fixed-size: remove one and add one per iteration.

For variable-size: adjust window by expanding right and shrinking left based on condition.

Track values like counts, frequency, uniqueness, or presence.

Always test edge cases: empty input, window size 0, all same elements, etc.

---

## Common Sliding Window Problems

| Problem | Type |
|--------|------|
| [Leetcode 3: Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Variable |
| [Leetcode 1456: Max Vowels in Substring of Length K](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/) | Fixed |
| [Leetcode 567: Permutation in String](https://leetcode.com/problems/permutation-in-string/) | Fixed + Hash Map |
| [Leetcode 76: Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | Variable + Target Map |
| [Leetcode 239: Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | Fixed + Deque |

---

## Summary

Sliding window is a go-to technique for linear-time solutions involving contiguous segments.  
Use **fixed-size** when the window length is static, and **variable-size** when constraints control window size dynamically.  
Combine with sets, maps, or counters as needed to track what's inside the window efficiently.

---
