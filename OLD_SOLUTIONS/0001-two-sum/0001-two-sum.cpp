class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // unordered map to store elements and indices
        for(int i = 0; i <nums.size(); i++){
            if(!map.contains(target-nums[i])) // check if the complement for the current element is in the map.
                map[nums[i]] = i; // add current index to map if the complment does not exist.
                else return {i, map[target-nums[i]]}; // return the current index and the index of the complement if found.
        }
        return {}; // no pair found.
    }
};