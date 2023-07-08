class Solution {
public:
    
    int ways(int n){
        int prev1 = 1;
        int prev2 = 1;
        int cur = 1;
        for(int i=2; i<=n; i++){
            cur = prev1 + prev2;
            prev1 = prev2;
            prev2 = cur;
        }
        return cur;
    }
    
    int climbStairs(int n) {
        return ways(n);
    }
};