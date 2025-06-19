/*
 * Concept: Two Pointers (C++ Templates)
 *
 * Goal:
 * Use two indices to traverse a sequence from different directions or with different speeds
 * to solve problems more efficiently than brute-force.
 *
 * Types:
 * - Opposite pointers (e.g., one from left, one from right)
 * - Same-direction pointers (e.g., slow/fast or overwrite pointers)
 *
 * Key Use Cases:
 * - Palindrome checks
 * - Pairing elements (sum, diff, etc.)
 * - In-place array editing (removal, sorting)
 * - Partitioning / merging
 *
 * Time Complexity: O(n)
 *   - Each pointer typically moves at most n steps
 *
 * Space Complexity: O(1)
 *   - Usually done in-place with no extra storage
 */

/*
 * -------------------------------
 * Opposite-Direction Two Pointers
 * -------------------------------
 * Use when you want to check symmetry or pairs from both ends.
 */

bool isPalindrome(string& s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        if (tolower(s[left]) != tolower(s[right])) return false;

        left++;
        right--;
    }

    return true;
}

/*
 * -------------------------------
 * Same-Direction Two Pointers
 * -------------------------------
 * Use when writing or scanning in-place (e.g., removing elements).
 */

int removeElement(vector<int>& nums, int val) {
    int write = 0;
    for (int read = 0; read < nums.size(); ++read) {
        if (nums[read] != val) {
            nums[write++] = nums[read];
        }
    }
    return write; // length of modified array
}

/*
 * -------------------------------
 * Tips to Remember
 * -------------------------------
 * - Use opposite pointers for problems involving symmetry (palindromes, reversing)
 * - Use same-direction pointers for in-place modifications or merging
 * - Be careful with pointer bounds (left < right vs left <= right)
 * - Combine with sorting for efficient search or pairing logic
 *
 * -------------------------------
 * Common Two Pointer Problems
 * -------------------------------
 * - Leetcode 125: Valid Palindrome (opposite)
 * - Leetcode 167: Two Sum II (sorted array)
 * - Leetcode 283: Move Zeroes (same-direction overwrite)
 * - Leetcode 680: Valid Palindrome II (skip one mismatch)
 * - Leetcode 26: Remove Duplicates from Sorted Array
 *
 * -------------------------------
 * Summary
 * -------------------------------
 * Two pointers is a versatile strategy used to reduce time complexity
 * from O(n^2) to O(n) in problems involving arrays or strings.
 * It is especially useful when you can process elements from both ends
 * or overwrite values in-place.
 */
