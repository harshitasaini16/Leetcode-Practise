class Solution {
public:
    int dy[3]={-1,0,1};
    int dp[100][100][100];
    int fun(int x,int y1,int y2,int n,int m,vector<vector<int>>& grid){
        if(x==n){
            return 0;
        }
        if(dp[x][y1][y2]!=-1){
            return dp[x][y1][y2];
        }
        int s=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int yy1=y1+dy[i];
                int yy2=y2+dy[j];
                if(yy1>=0 && yy2>=0 && yy1<m && yy2<m){
                    s=max(s,fun(x+1,yy1,yy2,n,m,grid));
                }
            }
        }
        if(y1==y2){
            return dp[x][y1][y2]=grid[x][y1]+s;
        }
        return dp[x][y1][y2]=grid[x][y1]+grid[x][y2]+s;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        return fun(0,0,m-1,n,m,grid);
    }
};