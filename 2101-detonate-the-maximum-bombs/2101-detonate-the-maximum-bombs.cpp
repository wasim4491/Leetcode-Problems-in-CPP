class Solution {
public:
    bool check(int x1, int y1, int x2, int y2, int r){
        if ((long)r * r >= (long)(x1 - x2) * (x1 - x2) + (long)(y1 - y2) * (y1 - y2)){
            return true;
        }
        return false;
    }
    int bfs(unordered_map<int, vector<int>> adj, int index, vector<bool> visited){
        queue<int> q;
        q.push(index);
        int count = 0;
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            count++;
            visited[ind] = true;
            for(auto it : adj[ind]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> adj;
        int n = bombs.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n ;j++){
                if(check(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1], bombs[i][2])){
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<bool> visited(n, false);
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                maxi = max(maxi, bfs(adj, i, visited));
            }
        }
        return maxi;
    }
};