class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int ans=0;
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    // cout<<i<<' '<<j<<endl;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int xx=x+dx[k];
                            int yy=y+dy[k];
                            if(xx<n && yy<m && xx>=0 && yy>=0 && grid[xx][yy]=='1'){
                                grid[xx][yy]='0';
                                q.push({xx,yy});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};