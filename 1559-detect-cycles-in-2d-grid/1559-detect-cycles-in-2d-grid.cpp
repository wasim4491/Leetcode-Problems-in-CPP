class Solution {
public:
    bool dfs(vector<vector<char>>& grid, vector<vector<int>> &visited, char node, int pi, int pj, int i, int j, int m, int n){
        visited[i][j] = 1;
        if(i-1>=0 && grid[i-1][j] == node && visited[i-1][j] == 1 && (pi!=i-1 || pj!=j)){
            return true;
        }
        if(i+1<m && grid[i+1][j] == node && visited[i+1][j] == 1 && (pi!=i+1 || pj!=j)){
            return true;
        }
        if(j-1>=0 && grid[i][j-1] == node && visited[i][j-1] == 1 && (pi!=i || pj!=j-1)){
            return true;
        }
        if(j+1 < n && grid[i][j+1] == node && visited[i][j+1] == 1 && (pi!=i || pj!=j+1)){
            return true;
        }
        if(i-1>=0 && grid[i-1][j] == node && visited[i-1][j] == 0){
            visited[i-1][j] = 1;
            bool temp = dfs(grid,visited,node,i,j,i-1,j,m,n);
            if(temp == 1){
                return true;
            }
        }
        if(i+1<m && grid[i+1][j] == node && visited[i+1][j] == 0){
            visited[i+1][j] = 1;
            bool temp = dfs(grid,visited,node,i,j,i+1,j,m,n);
            if(temp == 1){
                return true;
            }
        }
        if(j-1>=0 && grid[i][j-1] == node && visited[i][j-1] == 0){
            visited[i][j-1] = 1;
            bool temp = dfs(grid,visited,node,i,j,i,j-1,m,n);
            if(temp == 1){
                return true;
            }
        }
        if(j+1 < n && grid[i][j+1] == node && visited[i][j+1] == 0){
            visited[i][j+1] = 1;
            bool temp = dfs(grid,visited,node,i,j,i,j+1,m,n);
            if(temp == 1){
                return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // int visited[m][n];
        // memset(visited,0,m*n*sizeof(int));
        //pair<int,int> parent = {-1,-1};
        vector<vector<int>> visited(m ,vector<int> (n, 0)); 
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == 0){
                    bool ans = dfs(grid,visited,grid[i][j],-1,-1,i,j,m,n);
                    if(ans == 1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};