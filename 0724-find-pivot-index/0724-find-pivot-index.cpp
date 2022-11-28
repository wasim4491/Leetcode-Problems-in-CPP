class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum = 0, rightsum = 0,ans = -1,flag = 1,n=nums.size();
        for(int i=0;i<nums.size();i++){
            leftsum += nums[i];
        }
        for(int i=0;i<nums.size();i++){
            leftsum = leftsum - nums[i];
            if(rightsum == leftsum){
                ans = i;
                flag = 0;
                break;
            }
            rightsum += nums[i];
            
        }
        if(flag == 1){
            rightsum += nums[n-1];
            if(rightsum == leftsum){
                ans = n-1;
            }
        }
        
        cout << rightsum << " " <<leftsum;
        return ans;
    }
};