class Solution {
public:
    bool helper(vector<int> &nums, int i, int n, vector<int> &dp){
        if(i == n){
            return true;
        }
        if(i > n){
            return false;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        bool a = false, b = false, c = false;
        
        if(i+1 < n && nums[i] == nums[i + 1]){
            a = helper(nums, i+2, n, dp); 
            if(a == true){
                return dp[i] = true;
            }
        }
        
        if(i+2 < n && nums[i] == nums[i + 1] && nums[i + 1] == nums[i+2]){
            b = helper(nums, i+3, n, dp);
            if(b == true){
                return dp[i] = true;
            }
        }
        if(i+2 < n && nums[i] == nums[i+1] - 1 && nums[i+1] == nums[i+2] - 1){
            c = helper(nums, i+3, n, dp);
            if(c == true){
                return dp[i] = true;
            }
        }
        return dp[i] = (a || b) || c;
    }
    bool validPartition(vector<int>& nums) {
        int ind = 0;
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, ind, n, dp);
    }
};