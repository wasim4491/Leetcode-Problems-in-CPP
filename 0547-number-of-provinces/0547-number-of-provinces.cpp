class Solution {
public:
    bool check(int i, int j, int n){
        if(i < 0 || j < 0 || i >= n || j >= n){
            return false;
        }
        return true;
    }
    void bfs(unordered_map<int, vector<int>> adj, int ind, vector<bool> &visited){
        queue<int> q;
        q.push(ind);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            visited[temp] = true;
            for(auto it : adj[temp]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = true;
                }
            } 
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, true);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    visited[i] = false;
                    visited[j] = false;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(adj, i, visited);
                count++;
            }
        }
        return count;
    }
};