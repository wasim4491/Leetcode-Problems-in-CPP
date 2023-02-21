class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if(n == 1){
            ans.push_back(0);
            return ans;
        }
        if(n == 0){
            return ans;
        }
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        
        vector<int> degree(n);
        
        for(auto i : adj){
            for(auto j : i.second){
                degree[j]++;
            }
        }
        queue<int> que;
        for(int i=0;i<n;i++){
            if(degree[i] == 1){
                que.push(i);
            }
        }
        while(!que.empty()){
            int sz = que.size();
            ans.clear();
            for(int i=0;i<sz;i++){
                int fro = que.front();
                que.pop();
                degree[fro]--;
                ans.push_back(fro);
                for(auto i : adj[fro]){
                    degree[i]--;
                    if(degree[i] == 1){
                        que.push(i);
                    }
                }
            }
            
        }
        return ans;
    }
};