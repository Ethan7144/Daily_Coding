/**
 * Problem: Jump Game (Leetcode 55)
 *
 * Description:
 * Given an array of non-negative integers `nums`, where each element represents
 * the maximum jump length at that position, determine if you can reach the last index.
 *
 * Approach:
 * - Use a greedy algorithm to track the furthest reachable index.
 * - At each position, check if it's reachable.
 * - If it is, update the furthest reach (`reachable = max(reachable, i + nums[i])`).
 * - If a position is ever not reachable (i > reachable), return false.
 *
 * Time Complexity: O(n)
 *   - Each index is visited once.
 *
 * Space Complexity: O(1)
 *   - Constant space used for tracking `reachable`.
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > reachable) {
                return false; // Current index is beyond the furthest we can jump to
            }
            reachable = max(reachable, i + nums[i]); // Update max reach
        }
        return true; // Able to reach or pass the last index
    }
};
