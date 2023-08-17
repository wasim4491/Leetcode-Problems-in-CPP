#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    bool check(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

//     void bfs(vector<vector<int>>& mat, vector<vector<int>>& ans, int i, int j, int m, int n) {
//         queue<int> q;
//         q.push({i,j});
        
//         while(!q.empty()){
//             pair<int,int> temp = q.front();
//             q.pop();
//             int a = temp.first;
//             int b = temp.second;
//             if(check(a+1, b, m, n) && dp[a+1][b] == -1){
                
//             }
//         }
//     }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            int a = temp.first;
            int b = temp.second;
            if(check(a+1, b, m, n) && ans[a+1][b] == -1){
                q.push({a+1, b});
                ans[a+1][b] = 1 + ans[a][b];
            }
            if(check(a, b+1, m, n) && ans[a][b+1] == -1){
                q.push({a, b+1});
                ans[a][b+1] = 1 + ans[a][b];
            }
            if(check(a, b-1, m, n) && ans[a][b-1] == -1){
                q.push({a, b-1});
                ans[a][b-1] = 1 + ans[a][b];
            }
            if(check(a-1, b, m, n) && ans[a-1][b] == -1){
                q.push({a-1, b});
                ans[a-1][b] = 1 + ans[a][b];
            }
        }

        return ans;
    }
};
