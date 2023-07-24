class Solution {
public:
    void comb1help(vector<int>& candidates, int target, int ind, int sum, vector<vector<int>> &ans, vector<int> res){
        if(ind >= candidates.size()){
            return;
        }
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(res);
            return;
        }
        
        //pick element
        res.push_back(candidates[ind]);
        sum += candidates[ind];
        comb1help(candidates, target, ind, sum, ans, res);
        sum -= candidates[ind];
        res.pop_back();
        
        //not pick
        comb1help(candidates, target, ind+1, sum, ans, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        int ind = 0;
        int sum = 0;
        
        comb1help(candidates, target, ind, sum, ans, res);
        
        return ans;
    }
};