class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = 0, j = 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long int>> dp(m, vector<long long int> (n, 0));
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        
        //Intialize destination cell
        dp[m-1][n-1] = 1;
         //Intialize last row
        for(int j=n-2; j>=0; j--){
            if(obstacleGrid[m-1][j] == 0){
                dp[m-1][j] = dp[m-1][j+1];
            }
        }
        //Initialize last column
        for(int i=m-2; i>=0; i--){
            if(obstacleGrid[i][n-1] == 0){
                dp[i][n-1] = dp[i+1][n-1];
            }
        }
        
        //Initialize remaining elements
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};