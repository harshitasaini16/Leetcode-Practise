class Solution {
public:
    int dp[50];
    int fun(int n){
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n==0){
            return dp[n]=1;
        }
        return dp[n]=fun(n-1)+fun(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return fun(n);
    }
};