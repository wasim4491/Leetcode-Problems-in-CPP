class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        grid[i][j] = '0';
        
        if(i-1 >=0 && grid[i-1][j] == '1'){
            dfs(grid, i-1, j);
        }
        if(i+1 < m && grid[i+1][j] == '1'){
            dfs(grid, i+1, j);
        }
        if(j-1 >= 0 && grid[i][j-1] == '1'){
            dfs(grid, i, j-1);
        }
        if(j+1 < n && grid[i][j+1] == '1'){
            dfs(grid, i, j+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};