class Solution {
public:
    
    int money(vector<int> &nums, int n, vector<int> &dp){
        dp[0] = nums[0];
        int pick, notpick;
        for(int i=1; i<n; i++){
            pick = nums[i];
            notpick = dp[i-1];
            if(i > 1){
                pick += dp[i-2];
            }
            dp[i] = max(pick, notpick);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        return money(nums,n, dp);
    }
};