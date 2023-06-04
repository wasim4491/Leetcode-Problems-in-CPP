class Solution {
public:
    int dfs(int ind, vector<vector<int>> &adj, vector<int>& informtime){
        int maxi = 0;
        for(int i=0; i<adj[ind].size();i++){
            maxi = max(maxi, dfs(adj[ind][i], adj, informtime));
        }
        informtime[ind] += maxi;
        return informtime[ind];
    }
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1){
            return 0;
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        int time = dfs(headID, adj, informTime);
        return time;
    }
};