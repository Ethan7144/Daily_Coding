class Solution {
public:
    /*
     * Problem: Minimum Size Subarray Sum (LeetCode 209)
     * Approach: Sliding Window
     * 
     * Time: O(n)
     * Space: O(1)
     */
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();   
        int minLen = INT_MAX;
        int start = 0;
        int sum = 0;

        for(int end = 0; end < size; end++)
        {
            sum += nums[end];

            // Try to reduce the starting pos while the sum is valid
            while(sum >= target)
            {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
