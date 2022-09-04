class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dx[4]={-1,0,0,1};
        int dy[4]={0,-1,1,0};
        int n=grid.size();
        int ans=0;
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int xx=dx[k]+x;
                            int yy=dy[k]+y;
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