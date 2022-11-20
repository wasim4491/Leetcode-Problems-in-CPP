class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        vector<int> newarr(n-1);
        for(int i=0;i<n-1;i++){
            newarr[i] = (nums[i] + nums[i+1]) % 10;
            //cout << newarr[i] << " ";
        }
       // cout << endl;
        return triangularSum(newarr);
        
    }
};