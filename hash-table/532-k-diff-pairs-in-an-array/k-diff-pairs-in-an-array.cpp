class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0; // there is no valid pair for any neg nums
        unordered_map<int, int> freq;

        for (int num: nums){
                freq[num]++;

        }
        int count = 0;
        for(auto& [num, cnt] : freq){
            if(k == 0){
                if(cnt > 1)
                    count++;
            } 
            else{
                if(freq.count(num+k))
                    count++;
            }
        }
        return count;
        }
};