class Solution {
public:
    bool check(int i, int j, int m, int n){
        if(i >= m || j >= n || i < 0 || j < 0){
            return false;
        }
        return true;
    }
    int bfs(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int count = -1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair<int,int> temp = q.front();
                q.pop();
                int a = temp.first;
                int b = temp.second;
                if(check(a+1,b,m,n) && grid[a+1][b] == 1){
                    q.push({a+1,b});
                    grid[a+1][b] = 2;
                }
                if(check(a,b+1,m,n) && grid[a][b+1] == 1){
                    q.push({a,b+1});
                    grid[a][b+1] = 2;
                }
                if(check(a-1,b,m,n) && grid[a-1][b] == 1){
                    q.push({a-1,b});
                    grid[a-1][b] = 2;
                }
                if(check(a,b-1,m,n) && grid[a][b-1] == 1){
                    q.push({a,b-1});
                    grid[a][b-1] = 2;
                }
            }
            count++;
        }
        return count;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool flag = true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            return 0;
        }
        int ans = bfs(grid);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};