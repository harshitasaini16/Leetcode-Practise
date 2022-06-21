class Solution {
public:
    int dp[201][201];
    int fun(vector<vector<int>>& grid,int n,int m){
        if(n==1 && m==1){
            return grid[n-1][m-1];
        }
        if(n==1){
            return dp[n][m]=grid[n-1][m-1]+fun(grid,n,m-1);
        }
        if(m==1){
            return dp[n][m]=grid[n-1][m-1]+fun(grid,n-1,m);
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        return dp[n][m]=grid[n-1][m-1]+min(fun(grid,n-1,m),fun(grid,n,m-1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return fun(grid,grid.size(),grid[0].size());
    }
};