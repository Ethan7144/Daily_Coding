/*
 * Concept: Sliding Window (C++ Templates)
 *
 * Goal:
 * Efficiently analyze contiguous subarrays or substrings without recalculating from scratch.
 *
 * Types:
 * - Fixed-size window: Slide a window of constant size (e.g., length k)
 * - Dynamic-size window: Expand/shrink based on constraints (e.g., unique chars, valid sums)
 *
 * Key Use Cases:
 * - Maximum/minimum/average in subarrays of size k
 * - Longest substring with/without a condition
 * - Count of elements matching a pattern in a window
 *
 * Core Patterns:
 * 1. Fixed-size window:
 *    - Initialize the first window
 *    - Slide right by 1: add new element, remove old
 *
 * 2. Variable-size window:
 *    - Use two pointers (left, right)
 *    - Expand right, and shrink left when a condition is violated
 *
 * Time Complexity: O(n)
 *   - Each element is added and removed at most once
 *
 * Space Complexity: O(1) to O(k)
 *   - Depends on what you store inside the window (e.g., set, map, count)
 */

/*
 * -------------------------------
 * Fixed-Size Sliding Window
 * -------------------------------
 * Use when the window size is constant (e.g. length k).
 */

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
            maxResult = max(maxResult, ...); // custom logic here
        }
    }

    return maxResult;
}

/*
 * -------------------------------
 * Variable-Size Sliding Window
 * -------------------------------
 * Use when the window grows/shrinks based on a condition.
 */

int variableSizeSlidingWindow(string& s) {
    unordered_map<char, int> count;
    int left = 0, result = 0;

    for (int right = 0; right < s.size(); ++right) {
        count[s[right]]++;

        while (/* condition invalid */) {
            count[s[left]]--;
            if (count[s[left]] == 0) count.erase(s[left]);
            left++;
        }

        // Update result based on current window size
        result = max(result, right - left + 1); // or custom logic
    }

    return result;
}

/*
 * -------------------------------
 * Tips to Remember
 * -------------------------------
 * - Use a hash map or set to track characters/counts inside the window.
 * - For fixed-size: remove one and add one per step.
 * - For dynamic-size: adjust window when condition is violated.
 * - Count, frequency, or uniqueness are common properties to maintain.
 * - Always test edge cases: empty string, window size = 0, duplicates, etc.
 *
 * -------------------------------
 * Common Sliding Window Problems
 * -------------------------------
 * - Leetcode 3: Longest Substring Without Repeating Characters (variable)
 * - Leetcode 1456: Max Vowels in Substring of Length k (fixed)
 * - Leetcode 567: Permutation in String (fixed + map)
 * - Leetcode 76: Minimum Window Substring (variable + target map)
 * - Leetcode 239: Sliding Window Maximum (fixed + deque)
 *
 * -------------------------------
 * Summary
 * -------------------------------
 * Sliding window is a powerful technique for linear-time solutions on
 * problems involving contiguous sequences. Use fixed-size for uniform windows
 * and dynamic-size when conditions vary. Maintain state inside the window
 * efficiently to avoid recomputing from scratch.
 */
