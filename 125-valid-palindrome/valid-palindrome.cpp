/*
 * Problem: Valid Palindrome (Leetcode 125)
 *
 * Goal:
 * Determine if a given string is a palindrome, considering only alphanumeric characters and ignoring case.
 *
 * Approach:
 * - Use two pointers: one starting from the beginning, one from the end.
 * - Skip any non-alphanumeric characters using isalnum().
 * - Convert both characters to lowercase with tolower().
 * - Compare the characters; if any mismatch, return false.
 * - If all valid characters match, return true.
 *
 * Time Complexity: O(n)
 *   - Each character is visited at most once.
 *
 * Space Complexity: O(1)
 *   - Only uses a few variables, no extra data structures.
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right)
        {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            char a = tolower(s[left]);
            char b = tolower(s[right]);

            if(a != b){
                return false;
            } 
                left++;
                right--;
        }
        return true;
    }
};