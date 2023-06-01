class Solution {
public:
    bool check(int i, int j, int n){
        if(i >= n || i < 0 || j < 0 || j >= n){
            return false;
        }
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1){
            if(grid[0][0] == 1){
                return -1;
            }
            else{
                return 1;
            }
        }
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n, {-1, -1}));
        // vector<vector<pair<int,int>>> parent;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         parent[i][j] = {-1,-1};
        //     }
        // }
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            int i = temp.first;
            int j = temp.second;
            if(i == n-1 && j == n-1){
                break;
            }
            if(check(i+1, j, n) && grid[i+1][j] == 0 && !visited[i+1][j]){
                visited[i+1][j] = true;
                q.push({i+1,j});
                parent[i+1][j] = {i,j};
            }
            if(check(i-1, j, n) && grid[i-1][j] == 0 && !visited[i-1][j]){
                visited[i-1][j] = true;
                q.push({i-1,j});
                parent[i-1][j] = {i,j};
            }
            if(check(i, j+1, n) && grid[i][j+1] == 0 && !visited[i][j+1]){
                visited[i][j+1] = true;
                q.push({i,j+1});
                parent[i][j+1] = {i,j};
            }
            if(check(i, j-1, n) && grid[i][j-1] == 0 && !visited[i][j-1]){
                visited[i][j-1] = true;
                q.push({i,j-1});
                parent[i][j-1] = {i,j};
            }
            if(check(i+1, j+1, n) && grid[i+1][j+1] == 0 && !visited[i+1][j+1]){
                visited[i+1][j+1] = true;
                q.push({i+1,j+1});
                parent[i+1][j+1] = {i,j};
            }
            if(check(i-1, j-1, n) && grid[i-1][j-1] == 0 && !visited[i-1][j-1]){
                visited[i-1][j-1] = true;
                q.push({i-1,j-1});
                parent[i-1][j-1] = {i,j};
            }
            if(check(i+1, j-1, n) && grid[i+1][j-1] == 0 && !visited[i+1][j-1]){
                visited[i+1][j-1] = true;
                q.push({i+1,j-1});
                parent[i+1][j-1] = {i,j};
            }
            if(check(i-1, j+1, n) && grid[i-1][j+1] == 0 && !visited[i-1][j+1]){
                visited[i-1][j+1] = true;
                q.push({i-1,j+1});
                parent[i-1][j+1] = {i,j};
            }
        }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
                
//             }
//         }
        int i = parent[n-1][n-1].first, j = parent[n-1][n-1].second;
        if(i == -1 && j == -1){
            return -1;
        }
        int count = 1;
        int l, m;
       // for(int i=0;i<n;i++){
       //      for(int j=0;j<n;j++){
       //         cout << parent[i][j].first << " " << parent[i][j].second << endl;
       //      }
       //  }
        while(i != 0 || j != 0){
            l = parent[i][j].first;
            m = parent[i][j].second;
            count++;
            i = l;
            j = m;
           // cout << i << " " << j << endl;
            //cout << parent[i][j].first << " " << parent[i][j].second << endl;
            // if(i == -1 || j == -1){
            //     return -1;
            // }
        }
        return count+1;
    }
};