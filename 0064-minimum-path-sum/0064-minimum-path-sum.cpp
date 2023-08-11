class Solution {
public:
    bool check(int i, int j, int m, int n){
        if(i >= m || j >= n){
            return false;
        }
        return true;
    }
    int helper(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int total = grid[i][j];
        if(check(i+1, j, m, n) && check(i, j+1, m, n)){
            dp[i][j] = total + min(helper(grid, i+1, j, m, n, dp), helper(grid, i, j+1, m, n, dp));
        }
        else if(check(i+1, j, m, n) && !check(i, j+1, m, n)){
           dp[i][j] = total + helper(grid, i+1, j, m, n, dp);
        }
        else if(check(i, j+1, m, n) && !check(i+1, j, m, n)){
            dp[i][j] = total + helper(grid, i, j+1, m, n, dp);
        }
        else{
            dp[i][j] = total;
        }
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int i =0, j = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(grid, i, j, m, n, dp);
    }
};