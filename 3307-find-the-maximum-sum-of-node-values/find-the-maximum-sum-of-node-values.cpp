class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long base_sum = 0;
        vector<long long> deltas;

        for (int x : nums) {
            base_sum += x;
            long long gain = (x ^ k) - x;
            deltas.push_back(gain);
        }

        // Count how many gains are positive
        int toggle_count = 0;
        long long gain_sum = 0;

        for (long long d : deltas) {
            if (d > 0) {
                gain_sum += d;
                toggle_count++;
            }
        }

        // If number of positive-gain toggles is even → just take them
        if (toggle_count % 2 == 0) {
            return base_sum + gain_sum;
        }

        // Else → need to remove smallest gain to make even count
        long long smallest = LLONG_MAX;
        for (long long d : deltas) {
            smallest = min(smallest, abs(d));
        }

        return base_sum + gain_sum - smallest;
    }
};