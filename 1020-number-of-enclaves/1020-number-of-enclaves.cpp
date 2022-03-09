class Solution {
public:
    void fun(int x,int y,int n,int m,vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==0){
            return;
        }
        grid[x][y]=0;
        fun(x+1,y,n,m,grid);
        fun(x-1,y,n,m,grid);
        fun(x,y-1,n,m,grid);
        fun(x,y+1,n,m,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            fun(i,0,n,m,grid);
            fun(i,m-1,n,m,grid);
        }
        for(int i=0;i<m;i++){
            fun(0,i,n,m,grid);
            fun(n-1,i,n,m,grid);
        }
        int s=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s+=grid[i][j];
            }
        }
        return s;
    }
};