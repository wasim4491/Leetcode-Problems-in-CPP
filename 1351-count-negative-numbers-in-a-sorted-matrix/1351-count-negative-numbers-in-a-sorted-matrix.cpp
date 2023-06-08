class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        
        for(int i=0;i<grid.size();i++){
            int l = 0;
            int r = grid[0].size() - 1;
            int mid;
            if(grid[i][0] < 0){
                count += grid[i].size();
            }
            else if(grid[i][r] >= 0){
                count += 0;
            }
            else{
                while(l <= r){
                    mid = (l+r)/2;
                    if(mid-1 >= 0 && grid[i][mid - 1] >= 0 && grid[i][mid] < 0){
                        count += grid[i].size() - mid;
                        break;
                    }
                    else if(grid[i][mid] >= 0){
                        l = mid + 1;
                    }
                    else if(grid[i][mid] < 0){
                        r = mid - 1;
                    }
                }
            }
        }
        
        return count;
    }
};