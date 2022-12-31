class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0, maxcount = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    queue<pair<int,int>> que;
                    grid[i][j] = 2;
                    que.push({i,j});
                    while(!que.empty()){
                        pair<int,int> ans= que.front();
                        que.pop();
                        count = count + 1;
                        if(ans.first-1 >= 0 && ans.second >= 0 && 
                           ans.first-1 < grid.size() && ans.second<grid[0].size() && 
                           grid[ans.first-1][ans.second] == 1){
                            grid[ans.first-1][ans.second] = 2;
                            que.push({ans.first-1,ans.second});
                        }
                        if(ans.first>=0 && ans.second-1>=0 && 
                                ans.first<grid.size() && ans.second-1<grid[0].size() && 
                                grid[ans.first][ans.second-1] == 1){
                            grid[ans.first][ans.second-1] = 2;
                            que.push({ans.first,ans.second-1});
                        }
                        if(ans.first+1>=0 && ans.second>=0 && 
                                ans.first+1<grid.size() && ans.second<grid[0].size() && 
                                grid[ans.first+1][ans.second] == 1){
                            grid[ans.first+1][ans.second] = 2;
                            que.push({ans.first+1,ans.second});
                        }
                        if(ans.first>=0 && ans.second+1>=0 && 
                                ans.first<grid.size() && ans.second+1<grid[0].size() && 
                                grid[ans.first][ans.second+1] == 1){
                            grid[ans.first][ans.second + 1] = 2;
                            que.push({ans.first,ans.second+1});
                        }
                    }
                    maxcount = max(maxcount,count);
                    count = 0;
                }
            }
        }
        return maxcount;
    }
};