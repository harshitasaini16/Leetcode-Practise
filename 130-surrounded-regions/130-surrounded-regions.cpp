class Solution {
public:
    void fun(int x,int y,vector<vector<char>>& board,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m || board[x][y]=='X' || board[x][y]=='-'){
            return;
        }
        board[x][y]='-';
        fun(x+1,y,board,n,m);
        fun(x-1,y,board,n,m);
        fun(x,y+1,board,n,m);
        fun(x,y-1,board,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            fun(i,0,board,n,m);
            fun(i,m-1,board,n,m);
        }
        for(int i=0;i<m;i++){
            fun(0,i,board,n,m);
            fun(n-1,i,board,n,m);
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