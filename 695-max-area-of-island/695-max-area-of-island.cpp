class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int fun(int x,int y,vector<vector<int>>& grid,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==0){
            return 0;
        }
        int ans=0;
        grid[x][y]=0;
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            ans+=fun(xx,yy,grid,n,m);
        }
        return ans+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int s=fun(i,j,grid,n,m);
                    ans=max(ans,s);
                }
            }
        }
        return ans;
    }
};