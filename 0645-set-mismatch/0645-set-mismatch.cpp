class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int num1;
        int sum1 = (n * (n+1)) / 2;
        int sum2 = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                num1 = nums[i];
            }
            sum2 += nums[i];
        }
        sum2 += nums[n-1];
        // cout << sum1 << endl;
        // cout << sum2 << endl;
        
        vector<int> result;
        result.push_back(num1);
        result.push_back((sum1 - (sum2 - num1)));
        
        return result;
    }
};