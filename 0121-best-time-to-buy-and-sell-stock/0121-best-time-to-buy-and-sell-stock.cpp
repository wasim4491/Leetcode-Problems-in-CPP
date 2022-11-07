class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int initial = prices[0];
        int maxsum = 0;
        int diff;
        for(int i=1;i<prices.size();i++){
            if(initial > prices[i]){
                initial = prices[i];
            }
            else{
                diff = prices[i] - initial;
                maxsum = max(maxsum,diff);
            }
        }
        return maxsum;
    }
};