class Solution {
public:
    /*
     * Problem: Reorganize String (Leetcode 767)
     *
     * Goal:
     * Rearrange the characters of the input string so that no two adjacent characters are the same.
     * If it's not possible to do so, return an empty string.
     *
     * Approach:
     * - Count the frequency of each character.
     * - If the most frequent character occurs more than (n+1)/2 times, it's impossible to rearrange.
     * - Otherwise, place the most frequent character at even indices first.
     * - Then fill in the remaining characters in the remaining even and then odd indices.
     *
     * Time Complexity: O(n)
     *   - Counting frequency: O(n)
     *   - Placing characters: O(n)
     * Space Complexity: O(1)
     *   - Only 26 lowercase letters → constant size map
     */

    string reorganizeString(string s) {
        int strLength = s.length();
        int maxFreq = 0;            // Frequency of most frequent character
        char mostFreqChar = '#';    // Character with highest frequency

        // Step 1: Count frequency of each character
        unordered_map<char, int> freqMap;
        for (int i = 0; i < strLength; i++) {
            freqMap[s[i]]++;

            // Track the most frequent character
            if (freqMap[s[i]] > maxFreq) {
                maxFreq = freqMap[s[i]];
                mostFreqChar = s[i];
            }
        }

        // Step 2: Check if rearrangement is possible
        if (maxFreq > (strLength + 1) / 2)
            return "";  // Not possible if max frequency is more than half the length

        // Step 3: Fill the most frequent character in even indices
        int insertPos = 0;
        while (maxFreq > 0) {
            s[insertPos] = mostFreqChar;
            insertPos += 2;
            maxFreq--;
        }
        freqMap[mostFreqChar] = 0;  // Mark as used

        // Step 4: Fill remaining characters
        for (char c = 'a'; c <= 'z'; c++) {
            while (freqMap[c] > 0) {
                if (insertPos >= strLength) insertPos = 1;  // Switch to odd indices
                s[insertPos] = c;
                insertPos += 2;
                freqMap[c]--;
            }
        }

        return s;
    }
};