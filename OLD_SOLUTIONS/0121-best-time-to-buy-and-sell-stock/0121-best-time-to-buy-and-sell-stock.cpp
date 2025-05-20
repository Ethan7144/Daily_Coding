class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price_min = prices[0];
        int maxprof = 0;

        for(int i = 0; i < prices.size(); i++){
            maxprof = max(maxprof, prices[i] - price_min);
            price_min = min(prices[i], price_min);
        }

        return maxprof;
    }
};