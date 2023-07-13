class Solution {
public:
    bool dfs(int i, unordered_map<int, vector<int> > &adj, vector<bool> &visited, vector<bool> &dfsvisited){
        visited[i] = true;
        dfsvisited[i] = true;
        for(auto it : adj[i]){
            if(!visited[it]){
                if(dfs(it, adj, visited, dfsvisited) == true){
                    return true;
                }
            }
            else if(dfsvisited[it] == true){
                return true;
            }
        }
        dfsvisited[i] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() <= 1){
            return true;
        }
        unordered_map<int, vector<int> > adj;
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> dfsvisited(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, dfsvisited) == true){
                    return false;
                }
            }
        }
        return true;
    }
};