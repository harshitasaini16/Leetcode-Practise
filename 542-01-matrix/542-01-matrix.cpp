class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int s=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx<n && yy<m && xx>=0 && yy>=0 && mat[xx][yy]==1){
                    mat[xx][yy]=0;
                    ans[xx][yy]=s+1;
                    q.push({{xx,yy},s+1});
                }
            }
        }
        return ans;
    }
};