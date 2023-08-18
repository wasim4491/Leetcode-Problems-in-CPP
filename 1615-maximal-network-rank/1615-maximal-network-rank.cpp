class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> adj;
        vector<int> degree(n, 0);
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        
        for(int i=0; i<roads.size(); i++){
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
            connect[roads[i][0]][roads[i][1]] = true;
            connect[roads[i][1]][roads[i][0]] = true;
        }
        int maxi = -1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int temp = degree[i] + degree[j];
                if(connect[i][j] == true){
                    temp--;
                }
                if(temp > maxi){
                    maxi = temp;
                }
            }
        }
        
        return maxi;
    }
};