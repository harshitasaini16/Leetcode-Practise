class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void f(int x,int y,vector<vector<char>>&board,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m || board[x][y]=='X' || board[x][y]=='-'){
            return;
        }
        board[x][y]='-';
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            f(xx,yy,board,n,m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                f(i,0,board,n,m);
            }
            if(board[i][m-1]=='O'){
                f(i,m-1,board,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                f(0,i,board,n,m);
            }
            if(board[n-1][i]=='O'){
                f(n-1,i,board,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='-'){
                    board[i][j]='O';
                }
            }
        }
    }
};