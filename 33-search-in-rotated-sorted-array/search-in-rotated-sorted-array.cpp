class Solution {
/*
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return nums[mid];
            }
            else if (nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
};

*/
public:
        int search(vector<int>& nums, int target) {
            for(int i = 0; i < nums.size(); i++){
                if(target == nums[i]){
                    return i;
                }
            }
            return -1;
        }
};
