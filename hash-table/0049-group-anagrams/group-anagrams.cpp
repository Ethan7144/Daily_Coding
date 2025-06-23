class Solution {
public:
    /*
     * Problem: Group Anagrams (LeetCode 49)
     * Approach: HashMap + Sorting
     *
     * Summary:
     * - Anagrams have the same characters in different orders.
     * - If you sort each string, all anagrams become identical.
     * - Use a hash map with the sorted string as the key and group original words as values.
     *
     * Time: O(n * k log k)
     *   - n = number of strings
     *   - k = average string length (sorting each string)
     * Space: O(n * k) for the map and result
     */

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        vector<vector<string>> result;

        // Step 1: Group words by their sorted form
        for (string word : strs)
        {
            string key = word;               // Make a copy of the word
            sort(key.begin(), key.end());   // Sort to create the grouping key
            anagramGroups[key].push_back(word); // Append the original word to the group
        }

        // Step 2: Collect grouped anagrams from the map
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);  // Add each group to the result
        }

        return result;
    }
};
