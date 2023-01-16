class Solution {
public:
    bool cycledfs(int courses, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsvisited, int node){
        cout << node << endl;
        visited[node] = true;
        dfsvisited[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                bool ans = cycledfs(courses, adj, visited, dfsvisited, it);
                if(ans == 1){
                    return true;
                }
            }
            else if(dfsvisited[it]){
                return true;
            }
        }
        dfsvisited[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        if(prerequisites.size() == 0){
            return true;
        }
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            if(u == v){
                return false;
            }
            
            adj[v].push_back(u);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> dfsvisited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool res = cycledfs(numCourses, adj, visited, dfsvisited, i);
                if(res == 1){
                    cout << "Hi" << endl;
                    return false;
                }
            }
        }
        return true;
    }
};