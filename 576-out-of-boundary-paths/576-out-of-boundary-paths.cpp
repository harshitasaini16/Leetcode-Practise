class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0};
    int dp[51][51][51];
    int mod=1e9+7;
    int fun(int sr,int sc,int n,int m,int mm){
        if(sr<0 || sc<0 || sr>=n || sc>=m){
            return 1;
        }
        if(dp[sr][sc][mm]!=-1){
            return dp[sr][sc][mm];
        }
        if(mm==0){
            return 0;
        }
        long long ans=0;
        for(int i=0;i<4;i++){
            ans+=fun(sr+dx[i],sc+dy[i],n,m,mm-1)%mod;
        }
        return dp[sr][sc][mm]=ans%mod;
    }
    int findPaths(int n, int m, int mm, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return fun(sr,sc,n,m,mm);
    }
};