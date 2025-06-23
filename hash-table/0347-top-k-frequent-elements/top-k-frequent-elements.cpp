class Solution {
public:
    /*
     * Problem: Top K Frequent Elements (LeetCode 347)
     * Approach: Bucket Sort
     *
     * Summary:
     * - Use a hash map to count frequencies of each number.
     * - Create a "bucket" where index i holds all numbers that appear i times.
     * - Walk the bucket in reverse order (from most frequent to least), collecting numbers until we have k.
     *
     * Time: O(n)
     *   - O(n) to count frequencies
     *   - O(n) to place in buckets
     *   - O(n) to collect k results
     * Space: O(n)
     */

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency of each number
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Bucket sort - index = frequency, value = list of numbers
        vector<vector<int>> buckets(nums.size() + 1);  // max frequency can be n
        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        // Step 3: Collect top k frequent elements from the buckets (start from high freq)
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;  // stop once we have k elements
            }
        }

        return result;
    }
};