class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                q.push({i,j});
            }
        }
        int dx[4]={-1,0,0,1};
        int dy[4]={0,-1,1,0};
        int mx=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            mx=max(mx,ans[x][y]);
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0 && yy>=0 && xx<n && yy<m && mat[xx][yy]>mat[x][y] && ans[xx][yy]<=ans[x][y]){
                    ans[xx][yy]=ans[x][y]+1;
                    q.push({xx,yy});
                }
            }
        }
        return mx;
    }
};