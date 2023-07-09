class Solution {
public:
    
    int money(vector<int> &nums, int n){
        int prev1 = nums[0];
        int prev2 = 0, cur = nums[0];
        int pick, notpick;
        for(int i=1; i<n; i++){
            pick = nums[i];
            notpick = prev1;
            if(i > 1){
                pick += prev2;
            }
            cur = max(pick, notpick);
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1){
            return nums[0];
        }
        
        vector<int> temp1, temp2;
        
        for(int i=0; i<n; i++){
            if(i != 0){
                temp1.push_back(nums[i]);
            }
            if(i != n-1){
                temp2.push_back(nums[i]);
            }
        }
        
        return max(money(temp1, n-1), money(temp2, n-1));
    }
};