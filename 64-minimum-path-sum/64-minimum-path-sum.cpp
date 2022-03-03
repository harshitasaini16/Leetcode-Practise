class Solution {
public:
    map<pair<int,int>,int>dp;
    int f(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i>=n || j>=m){
            return INT_MAX;
        }
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(dp.find({i,j})!=dp.end()){
            return dp[{i,j}];
        }
        return dp[{i,j}]=grid[i][j]+min(f(i+1,j,n,m,grid),f(i,j+1,n,m,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.clear();
        return f(0,0,n,m,grid);
    }
};