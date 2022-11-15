class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> mp;
        int flag = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                mp.insert(nums[i]);
                flag = 0;
            }
        }
        if(flag == 1){
            return 0;
        }
        return mp.size();
    }
};