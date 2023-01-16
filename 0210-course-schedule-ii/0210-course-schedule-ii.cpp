class Solution {
public:
    bool cycledfs(int courses, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsvisited, int node, stack<int> &s){
        visited[node] = true;
        dfsvisited[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                bool ans = cycledfs(courses, adj, visited, dfsvisited, it, s);
                if(ans == 1){
                    return true;
                }
            }
            else if(dfsvisited[it]){
                return true;
            }
        }
        s.push(node);
        dfsvisited[node] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> ans;
        if(prerequisites.size() == 0){
            for(int i=0;i<numCourses;i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            if(u == v){
                return ans;
            }
            
            adj[v].push_back(u);
        }
        stack<int> s;
        vector<bool> visited(numCourses,false);
        vector<bool> dfsvisited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool res = cycledfs(numCourses, adj, visited, dfsvisited, i, s);
                if(res == 1){
                    return ans;
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};