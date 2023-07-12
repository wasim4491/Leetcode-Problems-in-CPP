class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = prices[0];
        int diff;
        int maxprofit = 0;
        for(int i=1; i<prices.size(); i++){
            diff = prices[i] - start;
            maxprofit = max(maxprofit, diff);
            start = min(start, prices[i]);
        }
        return maxprofit;
    }
};