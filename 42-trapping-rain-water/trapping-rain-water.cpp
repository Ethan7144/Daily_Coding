class Solution {
public:
    /**
     * Function: trap
     * ---------------------------------
     * Problem:
     *   Given a list of non-negative integers representing elevation heights,
     *   compute how much water can be trapped after raining.
     * 
     * Approach:
     *   - Use the two-pointer technique to traverse the elevation map from both ends.
     *   - Maintain running maximums from the left and right sides.
     *   - At each step, the amount of water trapped is determined by the smaller of the two max heights.
     *   - Always move the pointer on the side with the smaller max height to ensure valid trapping logic.
     * 
     * Time Complexity: O(n)
     *   - Each index is visited at most once.
     * 
     * Space Complexity: O(1)
     *   - Constant extra space used for variables.
     */
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        int ans = 0;

        while (left < right) {
            // Update max heights from both sides
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);

            // Water trapped is based on the shorter max side
            if (left_max < right_max) {
                ans += left_max - height[left];
                left++;
            } else {
                ans += right_max - height[right];
                right--;
            }
        }

        return ans;
    }
};
