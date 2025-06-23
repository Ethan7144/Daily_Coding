/**
 * Problem: Jump Game II (Leetcode 45)
 *
 * Description:
 * Given an array `nums` where each element represents the max jump length from that index,
 * return the minimum number of jumps needed to reach the last index.
 *
 * Approach:
 * - Use a greedy strategy to always jump to the farthest reachable position within the current range.
 * - Track:
 *    - `farthest`: the furthest we can reach while scanning the current range.
 *    - `end`: the boundary of the current jump.
 *    - `numJump`: number of jumps made so far.
 * - When the current index `i` reaches `end`, increment `numJump` and update `end` to `farthest`.
 * - We stop at `nums.size() - 2` since the last jump would land us at or beyond the last index.
 *
 * Time Complexity: O(n)
 *   - Each index is visited once.
 *
 * Space Complexity: O(1)
 *   - Only constant variables used.
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int farthest = 0;
        int numJump = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == end) {
                numJump++;
                end = farthest;
            }
        }

        return numJump;
    }
};
