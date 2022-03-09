class Solution {
public:
    void fun(int x,int y,vector<vector<int>>& grid1, vector<vector<int>>& grid2,int n,int m,int &g){
        if(x<0 || y<0 || x>=n || y>=m){
            return;
        }
        if(grid2[x][y]==0){
            return;
        }
        if(grid2[x][y]==1 && grid1[x][y]==0){
            g++;
            return;
        }
        grid2[x][y]=0;
        fun(x+1,y,grid1,grid2,n,m,g);
        fun(x-1,y,grid1,grid2,n,m,g);
        fun(x,y+1,grid1,grid2,n,m,g);
        fun(x,y-1,grid1,grid2,n,m,g);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        int s=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    int g=0;
                    fun(i,j,grid1,grid2,n,m,g);
                    if(g==0){
                        s++;
                    }
                }
            }
        }
        return s;
    }
};