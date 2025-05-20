class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Initialize index for placing non-target elements
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){ // If the current element is not the target value
                nums[k] = nums[i]; // Place the non-target element at the index position
                k++;
            }
        }
        return k;
    }
};