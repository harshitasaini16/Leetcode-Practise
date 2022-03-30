class Solution {
public:
    int dp[72][72][72];
    int dy[3]={-1,0,1};
    int fun(int x,int y1,int y2,vector<vector<int>>& grid,int n,int m){
        if(x==n-1){
            if(y1==y2){
                return grid[x][y1];
            }
            return grid[x][y1]+grid[x][y2];
        }
        if(dp[x][y1][y2]!=-1){
            return dp[x][y1][y2];
        }
        if(y1==y2){
            int s=grid[x][y1];
            int ans=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int yy1=y1+dy[i];
                    int yy2=y2+dy[j];
                    if(yy1>=0 && yy2>=0 && yy1<m && yy2<m){
                        ans=max(ans,fun(x+1,yy1,yy2,grid,n,m));
                    }
                }
            }
            return dp[x][y1][y2]=s+ans;
        }
        else{
            int s=grid[x][y1]+grid[x][y2];
            int ans=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int yy1=y1+dy[i];
                    int yy2=y2+dy[j];
                    if(yy1>=0 && yy2>=0 && yy1<m && yy2<m){
                        ans=max(ans,fun(x+1,yy1,yy2,grid,n,m));
                    }
                }
            }
            return dp[x][y1][y2]=s+ans;
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        return fun(0,0,m-1,grid,n,m);
    }
};