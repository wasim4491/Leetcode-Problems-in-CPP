class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //vector<pair<int,int>> ans;
        queue<pair<int,int>> res;
        res.push({sr,sc});
        int k = image[sr][sc];
        image[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();
        int visited[m][n];
        memset(visited, 0, m*n*sizeof(int));
        while(!res.empty()){
            pair<int,int> temp = res.front();
            res.pop();
            int u = temp.first;
            int v = temp.second;
            
            if(u-1>=0 && image[u-1][v] == k && visited[u-1][v] == 0){
                res.push({u-1,v});
                image[u-1][v] = color;
                visited[u-1][v] = 1;
            }
            if(u+1 < m && image[u+1][v] == k && visited[u+1][v] == 0){
                res.push({u+1,v});
                image[u+1][v] = color;
                visited[u+1][v] = 1;
            }
            if(v+1 < n && image[u][v+1] == k && visited[u][v+1] == 0){
                res.push({u,v+1});
                image[u][v+1] = color;
                visited[u][v+1] = 1;
            }
            if(v-1>=0 && image[u][v-1] == k && visited[u][v-1] == 0){
                res.push({u,v-1});
                image[u][v-1] = color;
                visited[u][v-1] = 1;
            }
        }
        return image;
    }
};