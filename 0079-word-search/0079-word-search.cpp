class Solution {
public:
    bool helperexist(vector<vector<char>>& grid, const string& word, int m, int n, int i, int j, int count, vector<vector<bool>>& visited) {
        if (count == word.length()) {
            return true;
        }
        
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] != word[count]) {
            return false;
        }
        
        visited[i][j] = true;
        bool exists = (helperexist(grid, word, m, n, i+1, j, count+1, visited) ||
                       helperexist(grid, word, m, n, i-1, j, count+1, visited) ||
                       helperexist(grid, word, m, n, i, j+1, count+1, visited) ||
                       helperexist(grid, word, m, n, i, j-1, count+1, visited));
        visited[i][j] = false;
        
        return exists;
    }
    
    bool exist(vector<vector<char>>& board, const string& word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (helperexist(board, word, m, n, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
