class Solution {
public:
    /*
     * Sliding Window + HashMap Approach
     *
     * Summary:
     * - Move through the string while tracking characters we've seen and their last positions.
     * - If a character repeats within the current window, move the start past its last occurrence.
     * - Continuously update the max length of a valid substring (no repeats).
     * 
     * Time: O(n), each character processed at most twice.
     * Space: O(min(n, m)), where m = charset size (e.g., 128 for ASCII).
     */

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> indexMap; // stores last seen index of characters
        int maxLen = 0;  // tracks the maximum substring length found
        int start = 0;   // left boundary of the current window

        for (int i = 0; i < s.size(); i++) {
            // If character is seen and is inside the current window
            if (indexMap.count(s[i]) && indexMap[s[i]] >= start) {
                // Move the window's start right after the last seen index of the repeating char
                start = indexMap[s[i]] + 1;
            }

            // Update the last seen index of the current character
            indexMap[s[i]] = i;

            // Update maxLen with the length of the current valid window
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};