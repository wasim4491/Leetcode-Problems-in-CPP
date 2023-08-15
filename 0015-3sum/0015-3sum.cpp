class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < n - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) { // Skip duplicates
                int l = i + 1, r = n - 1, target = -nums[i];
                while (l < r) {
                    if (nums[l] + nums[r] == target) {
                        ans.push_back({nums[i], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++; // Skip duplicates
                        while (l < r && nums[r] == nums[r - 1]) r--; // Skip duplicates
                        l++;
                        r--;
                    } else if (nums[l] + nums[r] < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        
        return ans;
    }
};
