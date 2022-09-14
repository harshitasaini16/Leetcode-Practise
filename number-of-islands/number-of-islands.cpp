class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int dx[4]={-1,0,0,1};
        int dy[4]={0,1,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int d=0;d<4;d++){
                            int xx=x+dx[d];
                            int yy=y+dy[d];
                            if(xx<n && yy<m && xx>=0 && yy>=0 && grid[xx][yy]=='1'){
                                q.push({xx,yy});
                                grid[xx][yy]='0';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};