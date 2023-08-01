class Solution {
public:
    void helper(vector<int> &temparr, vector<vector<int>> &mainarr, int ind, int n, int k){
        if(temparr.size() == k){
            mainarr.push_back(temparr);
            return;
        }
        if(ind > n){
            return;
        }
        
        //pick the element
        temparr.push_back(ind);
        helper(temparr, mainarr, ind+1, n, k);
        temparr.pop_back();
        
        //not pick
        helper(temparr, mainarr, ind+1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temparr;
        vector<vector<int>> mainarr;
        helper(temparr, mainarr, 1, n, k);
        
        return mainarr;
    }
};