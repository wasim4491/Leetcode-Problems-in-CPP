class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0){
            return ans;
        }
        string temp = "";
        for(int i=0; i < n-1; i++){
            if(temp == ""){
                temp = to_string(nums[i]);
            }
            if((long)nums[i+1] - (long)nums[i] != 1){
                if(temp != to_string(nums[i])){
                    temp = temp + "->" + to_string(nums[i]);
                }
                ans.push_back(temp);
                temp = "";
            }
        }
        if(temp == ""){
            temp = to_string(nums[n-1]);
        }
        else{
            temp = temp + "->" + to_string(nums[n-1]);
        }
        ans.push_back(temp);
        return ans;
    }
};