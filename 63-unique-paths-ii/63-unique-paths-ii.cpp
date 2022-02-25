class Solution {
public:
    map<pair<int,int>,int>dp;
    int fun(int i,int j,vector<vector<int>>mat,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j]==1){
            return 0;
        }
        if(dp.find({i,j})!=dp.end()){
            return dp[{i,j}];
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        mat[i][j]=1;
        return dp[{i,j}]=(fun(i+1,j,mat,n,m)+fun(i,j+1,mat,n,m));
    }
    int uniquePathsWithObstacles(vector<vector<int>>&mat) {
        dp.clear();
        return fun(0,0,mat,mat.size(),mat[0].size());
    }
};