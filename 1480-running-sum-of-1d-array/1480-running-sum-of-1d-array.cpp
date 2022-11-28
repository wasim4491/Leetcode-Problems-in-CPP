class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int count = nums[0];
        for(int i=1;i<n;i++){
            count += nums[i];
            nums[i] = count;
        }
        return nums;
    }
};