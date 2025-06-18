/*
 * Problem: Maximum Number of Vowels in a Substring of Given Length (Leetcode 1456)
 *
 * Goal:
 * Find the maximum number of vowels in any substring of length k in the given string.
 *
 * Approach:
 * - Use a fixed-size sliding window of size k.
 * - Maintain a running count of vowels in the current window.
 * - As the window slides:
 *     - Add 1 if the new character is a vowel.
 *     - Subtract 1 if the character sliding out is a vowel.
 *     - Update max count if needed.
 * - Use an unordered_set<char> for O(1) vowel checking.
 *
 * Time Complexity: O(n)
 *   - Each character is processed once.
 *
 * Space Complexity: O(1)
 *   - Constant space for the vowel set and integer counters.
 */

class Solution {
public:
    int maxVowels(string s, int k) {
        if(s.length() < k){
            return 0;
        }
        unordered_set<char> vowels = {'a','e','i','o','u'};

        int max_vowels = 0, window_vow = 0;

        for(int i = 0; i < s.length(); i++){
            if(vowels.count(s[i])){
                window_vow++;
            }
            if(i >= k && vowels.count(s[i - k])){
                window_vow--;
            }
            if(i >= k - 1) {
                max_vowels = max(max_vowels, window_vow);
            }
        }


        return max_vowels;
    }
};