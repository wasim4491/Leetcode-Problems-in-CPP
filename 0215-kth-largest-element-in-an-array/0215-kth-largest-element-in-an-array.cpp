class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> que;
        // for(int i=0; i<nums.size(); i++){
        //     que.push(nums[i]);
        // }
        // int ans;
        // while(k){
        //     ans = que.top();
        //     que.pop();
        //     k--;
        // }
        // return ans;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        
        vector<int> count(maxi-mini+1, 0);
        
        for(int i=0; i<nums.size(); i++){
            count[nums[i]-mini]++;
        }
        
        for(int i=count.size()-1; i>=0; i--){
            k = k - count[i];
            if(k <= 0){
                return i + mini;
            }
        }
        return -1;
    }
};