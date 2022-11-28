class Solution {
public:
    int sum(vector<int>& nums, int l, int r){
        int sums = 0;
        for(int i=l;i<=r;i++){
            sums += nums[i];
        }
        return sums;
    }
    int pivotIndex(vector<int>& nums) {
     //   int l = 0, r = nums.size()-1;
        int n = nums.size()-1;
      //  int mid = l + (r - l)/2;
        int ans = -1;
        for(int i=0;i<nums.size();i++){
            int sum1 = sum(nums,0,i-1);
            int sum2 = sum(nums,i+1,n);
            if(sum1 == sum2){
                ans = i;
                break;
            }
        }
        // while(l <= r){
        //     mid = l + (r - l)/2;
        //     int sum1 = sum(nums,0,mid-1);
        //     int sum2 = sum(nums,mid+1,n);
        //     if(sum1 == sum2){
        //         ans = mid;
        //         break;
        //     }
        //     else if(sum1 > sum2){
        //         r = mid - 1;
        //     }
        //     else{
        //         l = mid + 1;
        //     }
        // }
        return ans;
    }
};