class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mat[i-1][j-1]==1){
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
            }
        }
        int s=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                s+=dp[i][j];
            }
        }
        return s;
    }
};