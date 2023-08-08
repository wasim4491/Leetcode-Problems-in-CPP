class Solution {
public:
    int pivot(vector<int> &arr){
        int l = 0, r = arr.size() - 1;
        int mid;
        while(l < r){
            mid = l + (r - l)/2;
            if(arr[mid] < arr[r]){
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
    int bs(vector<int> &nums, int start, int end, int target){
        int l = start, r = end;
        int mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int piv = pivot(nums);
        if(nums[piv] == target){
            return piv;
        }
        int s1 = bs(nums, 0, piv-1, target);
        if(s1 != -1){
            return s1;
        }
        int s2 = bs(nums, piv, nums.size() - 1, target);
        return s2;
    }
};