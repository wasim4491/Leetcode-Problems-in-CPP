class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> averages(n, -1);
        
        if(k == 0){
            return nums;
        }
        if(n < 2*k + 1){
            return averages;
        }
        
        long long windowsum = 0;
        
        for(int i=0;i<(2*k + 1) ; i++){
            windowsum += nums[i];
        }
        
        averages[k] = windowsum / (2*k + 1);
        
        for(int i=(2*k+1); i<n; i++){
            windowsum = windowsum - nums[i-(2*k+1)] + nums[i];
            averages[i-k] = windowsum / (2*k + 1);
        }
        
        return averages;
    }
};