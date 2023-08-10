class Solution {
public:
    int helper(vector<int>& cost, int n, vector<int> &dp){
        if(n <= 1){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = min(helper(cost,n-1, dp) + cost[n-1], helper(cost, n-2, dp) + cost[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return helper(cost, n, dp);
    }
};