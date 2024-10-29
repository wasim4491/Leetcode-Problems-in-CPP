class Solution {
public:
    
    bool boundary(int m, int n, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return false;
        }
        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                
                if(!visited[i][j] && grid[i][j] == '1'){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int, int> temp = q.front();
                        q.pop();
                        int a = temp.first;
                        int b = temp.second;
                        if(boundary(m, n, a+1, b) && !visited[a+1][b] && grid[a+1][b] == '1'){
                            q.push({a+1, b});
                            visited[a+1][b] = true;
                        }
                        if(boundary(m, n, a-1, b) && !visited[a-1][b] && grid[a-1][b] == '1'){
                            q.push({a-1, b});
                            visited[a-1][b] = true;
                        }
                        if(boundary(m, n, a, b+1) && !visited[a][b+1] && grid[a][b+1] == '1'){
                            q.push({a, b+1});
                            visited[a][b+1] = true;
                        }
                        if(boundary(m, n, a, b-1) && !visited[a][b-1] && grid[a][b-1] == '1'){
                            q.push({a, b-1});
                            visited[a][b-1] = true;
                        }
                    }
                    count++;
                }
            }
        }
        
        return count;
    }
};