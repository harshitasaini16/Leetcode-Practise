class Solution {
public:
    int dp[201][201];
    int fun(int x,int y,vector<vector<int>>& triangle,int n){
        if(x==n){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        return dp[x][y]=triangle[x][y]+min(fun(x+1,y,triangle,n),fun(x+1,y+1,triangle,n));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,triangle,triangle.size());
    }
};