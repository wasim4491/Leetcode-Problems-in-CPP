class Solution {
public:
    bool check(int i, int j, int m, int n){
        if(i >= m || j >= n){
            return false;
        }
        return true;
    }
    int helper(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(!check(i, j, m, n) || grid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = helper(i+1, j, m, n, dp, grid) + helper(i, j+1, m, n, dp, grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = 0, j = 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(i, j, m, n, dp, obstacleGrid);
    }
};