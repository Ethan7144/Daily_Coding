class Solution {
public:
    /*
     * Problem: Maximum Subarray (LeetCode 53)
     * Approach: Kadane's Algorithm (Greedy/DP hybrid)
     *
     * Summary:
     * - We keep a running sum (`currentSum`) of the current subarray.
     * - If `currentSum` drops below 0, we reset it to 0.
     * - At each step, we update `maxSum` with the highest seen so far.
     *
     * Time: O(n), Space: O(1)
     */
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;

        for(int n : nums)
        {
            currSum = max(n, currSum + n);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};