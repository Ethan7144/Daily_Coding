/*
 * Problem: Valid Palindrome II (Leetcode 680)
 *
 * Goal:
 * Determine if a string can become a palindrome by removing at most one character.
 * Only alphanumeric characters are considered; case is ignored.
 *
 * Approach:
 * - Use two pointers (left and right) to scan from both ends.
 * - Skip non-alphanumeric characters and normalize to lowercase.
 * - On first mismatch:
 *     - Try skipping the left character (left + 1)
 *     - OR skip the right character (right - 1)
 *     - Use a helper function to check if either resulting substring is a palindrome.
 * - If no mismatches or one valid skip found, return true.
 *
 * Time Complexity: O(n)
 *   - Full scan with one possible nested scan (still linear).
 *
 * Space Complexity: O(1)
 *   - No extra space used beyond pointers and helper logic.
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right)
        {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            char a = tolower(s[left]);
            char b = tolower(s[right]);

            if(a != b){
                return isPalindromeRange(s, left + 1, right) || isPalindromeRange(s, left, right - 1);
            } 
                left++;
                right--;
        }
        return true;
    }

    bool isPalindromeRange(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
};