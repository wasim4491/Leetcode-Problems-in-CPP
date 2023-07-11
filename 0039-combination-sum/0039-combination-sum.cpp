class Solution {
public:
    void combsum(vector<int> candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int &sum, int ind, int n){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(sum > target || ind == n){
            return ;
        }
        
        
        // pick the elemet and not to move the index
        temp.push_back(candidates[ind]);
        sum += candidates[ind];
        combsum(candidates, target, temp, ans, sum, ind, n);
        temp.pop_back();
        sum -= candidates[ind];
        
        //not pick the element
        combsum(candidates, target, temp, ans, sum, ind+1, n);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int sum = 0;
        int ind = 0;
        int n = candidates.size();
        combsum(candidates, target, temp, ans, sum, ind, n);
        return ans;
    }
};