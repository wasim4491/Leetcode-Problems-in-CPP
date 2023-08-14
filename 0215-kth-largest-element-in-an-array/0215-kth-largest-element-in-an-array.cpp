class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> que;
        for(int i=0; i<nums.size(); i++){
            que.push(nums[i]);
        }
        int ans;
        while(k){
            ans = que.top();
            que.pop();
            k--;
        }
        return ans;
    }
};