class Solution {
public:
    bool check(int i, int j, int m, int n, vector<vector<bool>> &visited){
        if(i >= m || j >= n || i < 0 || j < 0 || visited[i][j] == true){
            return false;
        }
        return true;
    }
    void printright(vector<vector<int>>& matrix, vector<vector<bool>> &visited, int &x, int &y, int m, int n, vector<int> &ans, int &elements){
        if(!check(x,y,m,n,visited)){
            y--;
            return;
        }
        ans.push_back(matrix[x][y]);
        visited[x][y] = true;
        y++;
        elements--;
        printright(matrix, visited, x, y, m, n, ans, elements);
    }
    void printleft(vector<vector<int>>& matrix, vector<vector<bool>> &visited, int &x, int &y, int m, int n, vector<int> &ans, int &elements){
        if(!check(x,y,m,n,visited)){
            y++;
            return;
        }
        ans.push_back(matrix[x][y]);
        visited[x][y] = true;
        y--;
        elements--;
        printleft(matrix, visited, x, y, m, n, ans, elements);
    }
    void printup(vector<vector<int>>& matrix, vector<vector<bool>> &visited, int &x, int &y, int m, int n, vector<int> &ans, int &elements){
        if(!check(x,y,m,n,visited)){
            x++;
            return;
        }
        ans.push_back(matrix[x][y]);
        visited[x][y] = true;
        x--;
        elements--;
        printup(matrix, visited, x, y, m, n, ans, elements);
    }
    void printdown(vector<vector<int>>& matrix, vector<vector<bool>> &visited, int &x, int &y, int m, int n, vector<int> &ans, int &elements){
        if(!check(x,y,m,n,visited)){
            x--;
            return;
        }
        ans.push_back(matrix[x][y]);
        visited[x][y] = true;
        x++;
        elements--;
        printdown(matrix, visited, x, y, m, n, ans, elements);
    }
        
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int elements = m*n;
        vector<int> ans;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int x = 0, y = 0;
        while(elements){
            printright(matrix, visited, x, y, m, n, ans, elements);
            x++;
            printdown(matrix, visited, x, y, m, n, ans, elements);
            y--;
            printleft(matrix, visited, x, y, m, n, ans, elements);
            x--;
            printup(matrix, visited, x, y, m, n, ans, elements);
            y++;
        }
        return ans;
    }
};