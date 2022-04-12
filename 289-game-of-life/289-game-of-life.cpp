class Solution {
public:
    int dx[8]={0,1,1,-1,1,-1,-1,0};
    int dy[8]={1,0,1,-1,-1,1,0,-1};
    int fun(vector<vector<int>>& board,int n,int m,int x,int y){
        int live=0;
        for(int i=0;i<8;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<n && yy<m && xx>=0 && yy>=0){
                if(board[xx][yy]==1){
                    live++;
                }
            }
        }
        return live;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>ans=board;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live=fun(board,n,m,i,j);
                if(board[i][j]==1 && live<2){
                    ans[i][j]=0;
                }
                else if(board[i][j]==1 && (live==2 || live==3)){
                    ans[i][j]=1;
                }
                else if(board[i][j]==1 && live>3){
                    ans[i][j]=0;
                }
                else if(board[i][j]==0 && live==3){
                    ans[i][j]=1;
                }
            }
        }
        board=ans;
    }
};