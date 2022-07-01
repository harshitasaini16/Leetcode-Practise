class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    void fun(int x,int y,vector<vector<char>>& grid){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]=='0'){
            return;
        }
        grid[x][y]='0';
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            fun(xx,yy,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    fun(i,j,grid);
                }
            }
        }
        return ans;
    }
};