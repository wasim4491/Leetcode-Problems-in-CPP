class Solution {
public:
    int dfs(int i, string s, unordered_set<string> &dicset, vector<int> &dp){
        if(i == s.length()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int res = 1 + dfs(i + 1, s, dicset, dp);
        for(int j=1; j+i <= s.length(); j++){
            if(dicset.count(s.substr(i,j))){
                res = min(res, dfs(i+j, s, dicset, dp));
            }
        }
        return dp[i] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dicset(dictionary.begin(), dictionary.end());
        int n = s.length();
        vector<int> dp(n,-1);
        return dfs(0, s, dicset, dp);
    }
};