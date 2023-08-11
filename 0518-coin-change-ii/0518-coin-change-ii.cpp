class Solution {
public:
    int helper(vector<int>& coins, int amount, int sum, int ind, vector<vector<int>> &dp){
        if(sum == amount){
            return 1;
        }
        if(sum > amount){
            return 0;
        }
        if(ind >= coins.size()){
            return 0;
        }
        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }
        return dp[ind][sum] = helper(coins, amount, sum + coins[ind], ind, dp) + helper(coins, amount, sum, ind + 1, dp);
    }
    int change(int amount, vector<int>& coins) {
        int sum = 0, ind = 0;
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        return helper(coins, amount, sum, ind, dp);
    }
};