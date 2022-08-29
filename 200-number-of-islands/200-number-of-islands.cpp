class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dx[4]={-1,0,0,1};
        int dy[4]={0,-1,1,0};
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int g=0;g<4;g++){
                            int xx=x+dx[g];
                            int yy=y+dy[g];
                            if(xx>=0 && yy>=0 && xx<n && yy<m && grid[xx][yy]=='1'){
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