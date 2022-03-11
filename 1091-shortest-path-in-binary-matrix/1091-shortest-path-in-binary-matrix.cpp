class Solution {
public:
    int dx[8]={-1,-1,-1,0,1,1,1,0};
    int dy[8]={-1,0,1,1,1,0,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }
        map<pair<int,int>,int>vis;
        q.push({{0,0},1});
        vis[{0,0}]++;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int s=q.front().second;
            if(x==n-1 && y==m-1){
                return s;
            }
            q.pop();
            for(int i=0;i<8;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0 && yy>=0 && xx<n && yy<m && grid[x][y]==0 && vis[{xx,yy}]==0){
                    vis[{xx,yy}]++;
                    q.push({{xx,yy},s+1});
                }
            }
        }
        return -1;
    }
};