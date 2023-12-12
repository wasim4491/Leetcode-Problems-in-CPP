class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ind_1 = 0;
        int ind_2 = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[ind_1] < nums[i]){
                ind_1 = i;
            }
        }
        
        if(ind_1 == 0){
            ind_2 = 1;
        }
        
        for(int i=1; i<nums.size(); i++){
            if(i != ind_1 && nums[ind_2] < nums[i]){
                ind_2 = i;
            }
        }
        
        return (nums[ind_1] - 1) * (nums[ind_2] - 1);
    }
};