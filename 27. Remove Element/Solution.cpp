class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){ // if not equal, it is a non-target element
                nums[index] = nums[i]; // sets non target element to the position of index
                index++;
            }
        }
        return index;
    }
};