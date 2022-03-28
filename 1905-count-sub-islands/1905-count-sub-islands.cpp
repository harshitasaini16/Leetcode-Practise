class Solution {
public:
    map<pair<int,int>,int>mp;
    bool fun(int x,int y,vector<vector<int>>& grid1, vector<vector<int>>& grid2,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m || grid2[x][y]==0){
            return true;
        }
        if(mp.find({x,y})!=mp.end()){
            return mp[{x,y}];
        }
        if(grid2[x][y]==1 && grid1[x][y]==0){
            return false;
        }
        int p=grid1[x][y];
        int q=grid2[x][y];
        grid1[x][y]=0;
        grid2[x][y]=0;
        bool f=(fun(x+1,y,grid1,grid2,n,m) && fun(x-1,y,grid1,grid2,n,m) && fun(x,y-1,grid1,grid2,n,m) && fun(x,y+1,grid1,grid2,n,m));
        if(f==true){
            return mp[{x,y}]=true;
        }
        grid1[x][y]=p;
        grid2[x][y]=q;
        return mp[{x,y}]=false;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        mp.clear();
        int n=grid1.size();
        int m=grid1[0].size();
        int s=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    if(fun(i,j,grid1,grid2,n,m)){
                        s++;
                    }
                }
            }
        }
        return s;
    }
};