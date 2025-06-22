
## What Is String Manipulation?

String manipulation involves processing, parsing, and transforming strings using slicing, matching, or sliding windows.

---

## When to Use

* You need to analyze characters or substrings
* You’re solving problems involving matching, uniqueness, or patterns
* Use hashing + windowing for optimal string handling

---

## Key String Patterns (C++)

### Longest Substring Without Repeating Characters

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int left = 0, res = 0;
    for (int right = 0; right < s.length(); ++right) {
        if (map.count(s[right])) {
            left = max(map[s[right]] + 1, left);
        }
        map[s[right]] = right;
        res = max(res, right - left + 1);
    }
    return res;
}
```

### Minimum Window Substring

```cpp
string minWindow(string s, string t) {
    unordered_map<char, int> count;
    for (char c : t) count[c]++;
    int left = 0, right = 0, minLen = INT_MAX, start = 0, required = t.size();
    while (right < s.size()) {
        if (count[s[right++]]-- > 0) required--;
        while (required == 0) {
            if (right - left < minLen) minLen = right - (start = left);
            if (++count[s[left++]] > 0) required++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
```

---

## Tips to Remember

* Use maps to track char frequencies
* Sliding window shrinks when all conditions are met
* Use two pointers for substring range control
* Use hash to track uniqueness or anagram counts

---

## Common String Problems

| Problem                         | Why String Manipulation?              |
|----------------------------------|----------------------------------------|
| Longest Substring Without Repeat| Uniqueness in dynamic window           |
| Minimum Window Substring        | Include all target characters          |
| Group Anagrams                  | Normalize strings with frequency map   |
| Is Subsequence                  | One-pass pointer scan                  |

---

## String Summary

Strings are about careful windowing and hashing. Master substring control and character counts to ace most problems.
