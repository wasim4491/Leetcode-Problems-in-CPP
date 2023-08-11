class Solution {
    public int uniquePaths(int m, int n) {
        int[] dp = new int[n];
        for(int i = 0;i<m;i++){
            int[] temp = new int[n];
            for(int j = 0;j<n;j++)
                if(i==0 && j == 0) temp[j] = 1;
                else{
                    int down = 0,right = 0;
                    if(i>0) down = dp[j];
                    if(j>0) right = temp[j-1];
                    temp[j] = down+right;
                }
            dp = temp;
        }
        return dp[n-1];
    }
} 