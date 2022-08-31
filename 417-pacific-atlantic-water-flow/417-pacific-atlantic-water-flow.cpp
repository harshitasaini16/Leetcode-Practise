class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0};
    
    void fun(int x,int y,vector<vector<bool>>&v,int n,int m,vector<vector<int>>& heights){
        v[x][y]=true;
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0 && yy>=0 && xx<n && yy<m && v[xx][yy]==false && heights[x][y]<=heights[xx][yy]){
                fun(xx,yy,v,n,m,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>p(n,vector<bool>(m,false));
        vector<vector<bool>>a(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            fun(i,0,p,n,m,heights);
            fun(i,m-1,a,n,m,heights);
        }
        for(int i=0;i<m;i++){
            fun(0,i,p,n,m,heights);
            fun(n-1,i,a,n,m,heights);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==true && p[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};