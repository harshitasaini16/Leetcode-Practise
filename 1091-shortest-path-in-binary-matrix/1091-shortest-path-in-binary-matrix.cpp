class Solution {
public:
    int dx[8]={-1,-1,-1,0,1,1,1,0};
    int dy[8]={-1,0,1,1,1,0,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<pair<int,int>,int>>q;
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }
        q.push({{0,0},1});
        // map<pair<int,int>,int>vis;
        // vis[{0,0}]++;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int s=q.front().second;
            q.pop();
            if(x==n-1 && y==n-1){
                return s;
            }
            for(int i=0;i<8;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0 && yy>=0 && xx<n && yy<n && grid[xx][yy]==0){
                    grid[xx][yy]=1;
                    q.push({{xx,yy},s+1});
                }
            }
        }
        return -1;
    }
};