class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<bool> &dfsvisited){
        visited[node] = true;
        dfsvisited[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it, adj, visited, dfsvisited) == true){
                    return true;
                }
            }
            else if(visited[it] == true && dfsvisited[it] == true){
                return true;
            }
        }
        dfsvisited[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> dfsvisited(n, false);
        
        vector<int> cyclenodes;
        
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bool ans = dfs(i, adj, visited, dfsvisited);
            }
        }
        for(int j=0; j<n; j++){
             if(!dfsvisited[j]){
                cyclenodes.push_back(j);
            }
        }
        
//         unordered_set<int> presentNumbers;
//         vector<int> missingNumbers;

//         for (int num : cyclenodes) {
//             presentNumbers.insert(num);
//         }

//         for (int i = 0; i < n; i++) {
//             if (presentNumbers.find(i) == presentNumbers.end()) {
//                 missingNumbers.push_back(i);
//             }
//         }

        return cyclenodes;
    }
};