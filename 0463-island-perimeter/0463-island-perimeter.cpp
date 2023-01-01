class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0, maxcount = 0;
        int m = grid.size();
        int n = grid[0].size();
        int visited [m][n];
        memset(visited, 0, m*n*sizeof(int));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    visited[i][j] = 1;
                    while(!que.empty()){
                        pair<int,int> ans= que.front();
                        que.pop();
                        count = count + 4;
                        if(ans.first-1 >= 0 && ans.second >= 0 && 
                           ans.first-1 < grid.size() && ans.second<grid[0].size() && 
                           grid[ans.first-1][ans.second] == 1){
                            count--;
                            if(visited[ans.first-1][ans.second] == 0){
                                visited[ans.first-1][ans.second] = 1;
                                que.push({ans.first-1,ans.second});
                            }
                        }
                        if(ans.first>=0 && ans.second-1>=0 && 
                                ans.first<grid.size() && ans.second-1<grid[0].size() && 
                                grid[ans.first][ans.second-1] == 1){
                            count--;
                            if(visited[ans.first][ans.second-1] == 0){
                                visited[ans.first][ans.second-1] = 1;
                                que.push({ans.first,ans.second-1});
                            }
                        }
                        if(ans.first>=0 && ans.second+1>=0 && 
                                ans.first<grid.size() && ans.second+1<grid[0].size() && 
                                grid[ans.first][ans.second+1] == 1){
                            count--;
                            if(visited[ans.first][ans.second + 1] == 0){
                                visited[ans.first][ans.second + 1] = 1;
                                que.push({ans.first,ans.second+1});
                            }
                        }
                        if(ans.first+1>=0 && ans.second>=0 && 
                                ans.first+1<grid.size() && ans.second<grid[0].size() && 
                                grid[ans.first+1][ans.second] == 1){
                            count--;
                            if(visited[ans.first+1][ans.second] == 0){
                                visited[ans.first+1][ans.second] = 1;
                                que.push({ans.first+1,ans.second});
                            }
                        }
                        cout << count << endl;
                    }
                }
            }
        }
        return count;
    }
};