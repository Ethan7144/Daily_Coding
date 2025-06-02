class Solution {
public:
    /*
     * Problem: Valid Anagram (LeetCode 242)
     * Approach: Sort both strings and compare
     *
     * Time: O(n log n), due to sorting
     * Space: O(1), ignoring input size (in-place sort)
     */

    bool isAnagram(string s, string t) {
        // Anagrams must be same length
        if (s.length() != t.length()) return false;

        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // Compare sorted versions
        return s == t;
    }
};
