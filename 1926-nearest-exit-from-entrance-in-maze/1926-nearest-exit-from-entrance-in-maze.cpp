class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{entrance[0],entrance[1]},0});
        maze[entrance[0]][entrance[1]]='+';
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int s=q.front().second;
            if(x==0 || y==0 || x==n-1 || y==m-1){
                if(x==entrance[0] && y!=entrance[1]){
                return s;
            }
            if(x!=entrance[0] && y==entrance[1]){
                return s;
            }
            if(x!=entrance[0] && y!=entrance[1]){
                return s;
            }
            }
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0 && yy>=0 && xx<n && yy<m && maze[xx][yy]!='+'){
                    q.push({{xx,yy},s+1});
                    maze[xx][yy]='+';
                }
            }
        }
        return -1;
    }
};