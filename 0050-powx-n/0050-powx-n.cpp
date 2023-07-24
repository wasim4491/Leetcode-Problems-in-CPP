class Solution {
public:
    double helper (double x, long long n){
        if(n == 0){
            return 1.0;
        }
        if(n < 0){
            return 1.0/helper(x,-1 * n);
        }
        if(n % 2 == 1){
            return x *  helper(x * x, (n-1)/2);
        }
        else{
            return helper(x*x,n/2);
        }
    }
    double myPow(double x, int n) {
        return helper(x, (long long) n);
    }
};