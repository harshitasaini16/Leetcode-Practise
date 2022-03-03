  class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
    int r=grid.size();
    int c=grid[0].size();
    
    queue<pair<int,int>> q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==0){
                q.push({i,j});
            }
            else grid[i][j]=-1;
        }
    }
    int front=0;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    //if(q.empty() and front) return -1;
    while(!q.empty()){
        int n=q.size();
        front++;
        for(int i=0;i<n;i++){
        pair<int,int> p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=dx[i]+p.first;
            int y=dy[i]+p.second;
            if(x>-1 and y>-1 and x<r and y<c and grid[x][y]==-1){
                grid[x][y]=front;
                q.push({x,y});
                //front--;
            }
        }
        }
        
    }
   return grid; 
}
};