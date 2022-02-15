class Solution {
public:
    map<pair<int,int>,int>dp;
    int fun(int i,int j,int n,int m){
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp.find({i,j})!=dp.end()){
            return dp[{i,j}];
        }
        if(i==n-1){
            return dp[{i,j}]=fun(i,j+1,n,m);
        }
        if(j==m-1){
            return dp[{i,j}]=fun(i+1,j,n,m);
        }
        return dp[{i,j}]=fun(i+1,j,n,m)+fun(i,j+1,n,m);
    }
    int uniquePaths(int n, int m) {
        dp.clear();
        return fun(0,0,n,m);
    }
};