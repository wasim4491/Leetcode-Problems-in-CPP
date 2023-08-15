class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> mainarr;
        for(int i=0; i<n; i++){
            int l = i+1, r = n - 1;
            while(l < r){
                vector<int> subarr;
                if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }
                else if(nums[i] + nums[l] + nums[r] > 0){
                    r--;
                }
                else{
                    subarr.push_back(nums[l]);
                    subarr.push_back(nums[r]);
                    subarr.push_back(nums[i]);
                    mainarr.insert(subarr);
                    l++;
                    r--;
                }
            }
        }
        vector<vector<int>> ans(mainarr.begin(), mainarr.end());
        return ans;
    }
};