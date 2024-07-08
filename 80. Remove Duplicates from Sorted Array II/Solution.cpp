class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        
        // Loop through each element 'ele' in the vector 'nums'
        for(auto ele : nums)
        {
            // Check if the current position 'i' is 0 or 1, or if the current element is not the same as the element two positions before
            if(i == 0 || i == 1 || nums[i-2] != ele)
            {
                nums[i] = ele; // Assign the current element to the 'i-th' position
                i++;
            }
        }
        return i;
    }
};