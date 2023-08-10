class Solution {
public:
    int helper(vector<int>& nums, int ind, int n, vector<int>& memo){
        if(ind >= n){
            return 0;
        }
        
        if(memo[ind] != -1){
            return memo[ind];
        }
        
        int pick = nums[ind] + helper(nums, ind+2, n, memo);
        
        int notpick = helper(nums, ind+1, n, memo);
        
        memo[ind] = max(pick, notpick);
        return memo[ind];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        
        return helper(nums, 0, n, memo);
    }
};
