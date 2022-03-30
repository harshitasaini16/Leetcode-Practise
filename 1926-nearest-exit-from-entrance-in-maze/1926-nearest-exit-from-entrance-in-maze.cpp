class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& en) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{en[0],en[1]},0});
        maze[en[0]][en[1]]='+';
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int s=q.front().second;
            if(x==0 || y==0 || x==n-1 || y==m-1){
                if(x==en[0] && y!=en[1]){
                    return s;
                }
                if(x!=en[0] && y==en[1]){
                    return s;
                }
                if(x!=en[0] && y!=en[1]){
                    return s;
                }
            }
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0 && yy>=0 && xx<n && yy<m && maze[xx][yy]=='.'){
                    q.push({{xx,yy},s+1});
                    maze[xx][yy]='+';
                }
            }
        }
        return -1;
    }
};