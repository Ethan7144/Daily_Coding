/*
Summary:
---------
This solution finds the maximum frequency of any number in the array 
that can be achieved by "flipping" some occurrences of `k` into another number `m`.

Problem Assumption:
- You are allowed to change any number of `k`s into another number `m`
  (no cost or limit given in this variation).
- Your goal is to maximize the number of occurrences of any number after doing so.

Approach:
- Try every possible value `m` in the range [1, 50] (assuming problem bounds).
- Use a modified form of Kadane's Algorithm:
  - Treat the array like a score system where:
    - `+1` if element is `m` (a target match)
    - `-1` if element is `k` (a flip opportunity that "costs")
    - `0` otherwise
- For each `m`, find the subarray with the highest score — representing
  the best place to flip `k`s into `m`s to maximize `m`'s frequency.

- Finally, return the original number of `k`s plus the best flip score 
  (i.e., how many `k`s we can turn into the most beneficial `m`).

Time Complexity: O(50 * n) — loop over all values `m` and scan array each time
Space Complexity: O(1) — only scalar variables are used
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Count the original number of times `k` appears in the array
        int orig = count(nums.begin(), nums.end(), k);
        int mx = 0; // Tracks the best frequency gain from flipping k -> some m

        // Try every possible value of m (except k itself)
        for (int m = 1; m <= 50; ++m) {
            if (m == k) continue;

            int cur = 0;    // Current score for Kadane's
            int mxCur = 0;  // Max score for this particular m

            // Traverse the array to simulate flipping k → m
            for (int n : nums) {
                // Add +1 if current number is m (we want more m's)
                // Subtract -1 if current number is k (we can flip it)
                // Do nothing for other values
                cur += n == m ? 1 : n == k ? -1 : 0;

                // Reset score if it goes negative (Kadane’s logic)
                cur = max(cur, 0);

                // Update max score for current m
                mxCur = max(mxCur, cur);
            }

            // Track the best frequency gain across all possible m's
            mx = max(mx, mxCur);
        }

        // Result is original count of k + best number of flips into any m
        return orig + mx;
    }
};
