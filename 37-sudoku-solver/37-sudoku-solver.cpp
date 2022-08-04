class Solution {
public:
    bool f(int x,int y,vector<vector<char>>& board,char c){
        for(int i=0;i<9;i++){
            if(board[i][y]==c){
                return false;
            }
        }
        for(int j=0;j<9;j++){
            if(board[x][j]==c){
                return false;
            }
        }
        int a=x-x%3;
        int b=y-y%3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i+a][j+b]==c){
                    return false;
                }
            }
        }
        return true;
    }
    bool fun(int x,int y,vector<vector<char>>& board){
        if(x>=9){
            return true;
        }
        if(y>=9){
            return fun(x+1,0,board);
        }
        if(board[x][y]!='.'){
            return fun(x,y+1,board);
        }
        for(char c='1';c<='9';c++){
            if(f(x,y,board,c)){
                board[x][y]=c;
                if(fun(x,y+1,board)){
                    return true;
                }
                board[x][y]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        fun(0,0,board);
    }
};