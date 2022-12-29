class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    queue<pair<int,int>> que;
                    count++;
                    grid[i][j] = '2';
                    que.push({i,j});
                    while(!que.empty()){
                       // cout << "hi - " << grid[1][1] << endl;
                        pair<int,int> ans= que.front();
                        que.pop();
                      //  cout << ans.first << ans.second << endl;
                        if(ans.first-1 >= 0 && ans.second >= 0 && 
                           ans.first-1 < grid.size() && ans.second<grid[0].size() && 
                           grid[ans.first-1][ans.second] == '1'){
                       //     cout << ans.first-1 << " - " << ans.second << "-->" << grid[ans.first-1][ans.second] << endl;
                            grid[ans.first-1][ans.second] = '2';
                            que.push({ans.first-1,ans.second});
                        }
                        if(ans.first>=0 && ans.second-1>=0 && 
                                ans.first<grid.size() && ans.second-1<grid[0].size() && 
                                grid[ans.first][ans.second-1] == '1'){
                            grid[ans.first][ans.second-1] = '2';
                            que.push({ans.first,ans.second-1});
                        }
                        if(ans.first+1>=0 && ans.second>=0 && 
                                ans.first+1<grid.size() && ans.second<grid[0].size() && 
                                grid[ans.first+1][ans.second] == '1'){
                            grid[ans.first+1][ans.second] = '2';
                            que.push({ans.first+1,ans.second});
                        }
                        if(ans.first>=0 && ans.second+1>=0 && 
                                ans.first<grid.size() && ans.second+1<grid[0].size() && 
                                grid[ans.first][ans.second+1] == '1'){
                            grid[ans.first][ans.second + 1] = '2';
                            que.push({ans.first,ans.second+1});
                        }
                        
                    }
                }
            }
        }
        return count;
    }
};