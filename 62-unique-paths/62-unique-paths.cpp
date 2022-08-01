class Solution {
public:
    int dp[101][101];
    int fun(int n,int m){
        if(n==1 && m==1){
            return 1;
        }
        if(n==1){
            return fun(n,m-1);
        }
        else if(m==1){
            return fun(n-1,m);
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        return dp[n][m]=fun(n-1,m)+fun(n,m-1);
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return fun(m,n);
    }
};