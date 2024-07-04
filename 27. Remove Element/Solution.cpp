class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0; // Initialize index for placing non-target elements
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){ // If the current element is not the target value
                nums[index] = nums[i]; // Place the non-target element at the index position
                index++;
            }
        }
        return index;
    }
};