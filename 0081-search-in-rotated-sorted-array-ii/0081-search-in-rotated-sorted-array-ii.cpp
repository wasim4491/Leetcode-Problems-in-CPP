class Solution {
public:
    int pivot(vector<int>& nums){
        int l = 0, r = nums.size() - 1;
        int mid;
        
        while(l < r){
            mid = l + (r - l)/2;
            if(nums[mid] <= nums[r]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
    bool binarysearch(vector<int>& nums, int target, int l, int r){
        int mid;
        while(l <= r){
            mid = l + (r - l)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int piv = pivot(nums);
        bool s1 = binarysearch(nums, target, 0, piv-1);
        bool s2 = binarysearch(nums, target, piv, nums.size()-1);
        if((s1 || s2) == false){
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == target){
                    return true;
                }
            }
            return false;
        }
        return true;
    }
};