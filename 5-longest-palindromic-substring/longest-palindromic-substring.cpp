class Solution {
public:
    /**
     * Function: longestPalindrome
     *
     * Goal:
     *   Find the longest palindromic substring in the given string `s`.
     *
     * Approach:
     *   - For each character in the string, consider it as the center of a potential palindrome.
     *   - Expand outward from that center for both:
     *       - Odd-length palindromes (single center at `i`)
     *       - Even-length palindromes (dual center between `i` and `i+1`)
     *   - Keep track of the start and end indices of the longest palindrome found.
     *
     * Time Complexity: O(n^2)
     *   - We expand from each center at most O(n) times.
     *
     * Space Complexity: O(1)
     *   - No extra space used beyond constant variables.
     */
    string longestPalindrome(string s) {
        int start = 0;  // Starting index of the longest palindrome
        int end = 0;    // Ending index of the longest palindrome

        for (int i = 0; i < s.size(); ++i) {
            // Expand around single center (odd-length palindrome)
            auto [left1, right1] = expandFromCenter(s, i, i);
            // Expand around double center (even-length palindrome)
            auto [left2, right2] = expandFromCenter(s, i, i + 1);

            // Update longest palindrome if needed (odd case)
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }

            // Update longest palindrome if needed (even case)
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }

        // Return the longest palindromic substring
        return s.substr(start, end - start + 1);
    }

    /**
     * Function: expandFromCenter
     *
     * Expands pointers `left` and `right` outward as long as the characters match,
     * indicating a palindrome around the given center.
     *
     * Returns:
     *   A pair of integers representing the start and end indices of the palindrome found.
     */
    pair<int, int> expandFromCenter(const string& s, int left, int right) {
        // Expand outward as long as characters match and bounds are valid
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // We've expanded one step too far on both sides
        return {left + 1, right - 1};
    }
};
