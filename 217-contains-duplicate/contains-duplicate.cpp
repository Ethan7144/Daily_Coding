class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seenNums; // maps value to its index

        for (int i = 0; i < nums.size(); i++) {
            int complement = nums[i]; // what we need to find

            // If we've seen the complement before, return the two indices
            if (seenNums.find(complement) != seenNums.end()) {
                return true;
            }

            // Otherwise, store the current number with its index
            seenNums[nums[i]] = i;
        }

        // If no solution found (shouldn't happen per problem constraints)
        return false;
    }
};