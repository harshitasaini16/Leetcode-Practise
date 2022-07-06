class Solution {
public:
    int dp[101][10001];
    int fun(int x,int n){
        if(n==0){
            return 0;
        }
        if(n<0 || x==0){
            return INT_MAX-1;
        }
        if(dp[x][n]!=-1){
            return dp[x][n];
        }
        int s=x*x;
        if(s<=n){
            return dp[x][n]=min(1+fun(x,n-s),fun(x-1,n));
        }
        return dp[x][n]=fun(x-1,n);
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return fun(100,n);
    }
};