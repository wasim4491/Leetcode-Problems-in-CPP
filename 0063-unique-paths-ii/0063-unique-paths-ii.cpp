class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }

        obstacleGrid[m - 1][n - 1] = 1; // Initialize the destination cell

        // Fill the last row
        for (int j = n - 2; j >= 0; j--) {
            if (obstacleGrid[m - 1][j] == 0) {
                obstacleGrid[m - 1][j] = obstacleGrid[m - 1][j + 1];
            } else {
                obstacleGrid[m - 1][j] = 0; // Set to 0 if there's an obstacle
            }
        }

        // Fill the last column
        for (int i = m - 2; i >= 0; i--) {
            if (obstacleGrid[i][n - 1] == 0) {
                obstacleGrid[i][n - 1] = obstacleGrid[i + 1][n - 1];
            } else {
                obstacleGrid[i][n - 1] = 0; // Set to 0 if there's an obstacle
            }
        }

        // Fill the rest of the grid bottom-up
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = (long long) obstacleGrid[i + 1][j] + obstacleGrid[i][j + 1];
                } else {
                    obstacleGrid[i][j] = 0; // Set to 0 if there's an obstacle
                }
            }
        }

        return obstacleGrid[0][0];
    }
};
