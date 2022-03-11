class Solution {
public:
    void fun(int x,int y,vector<vector<bool>>&vis,vector<vector<int>>h,int n,int m){
        vis[x][y]=true;
        if(x+1<n && y<m && x+1>=0 && y>=0 && vis[x+1][y]==false && h[x][y]<=h[x+1][y]){
            fun(x+1,y,vis,h,n,m);
        }
        if(x-1<n && y<m && x-1>=0 && y>=0 && vis[x-1][y]==false && h[x][y]<=h[x-1][y]){
            fun(x-1,y,vis,h,n,m);
        }
        if(x<n && y+1<m && x>=0 && y>=0 && vis[x][y+1]==false && h[x][y]<=h[x][y+1]){
            fun(x,y+1,vis,h,n,m);
        }
        if(x<n && y-1<m && x>=0 && y-1>=0 && vis[x][y-1]==false && h[x][y]<=h[x][y-1]){
            fun(x,y-1,vis,h,n,m);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<bool>>visp(n,vector<bool>(m,false));
        vector<vector<bool>>visa(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            fun(i,0,visp,h,n,m);
            fun(i,m-1,visa,h,n,m);
        }
        for(int i=0;i<m;i++){
            fun(0,i,visp,h,n,m);
            fun(n-1,i,visa,h,n,m);
        }
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visp[i][j]==true && visa[i][j]==true){
                    v.push_back({i,j});
                }
            }
        }
        return v;
    }
};