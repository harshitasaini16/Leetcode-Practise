class Solution {
public:
    bool valid(vector<vector<char>>&arr,int i,int j,int val){
        for(int k=0;k<9;k++){
            if(arr[i][k]==val or arr[k][j]==val){
                return false;
            } 
        }
        int x=i-i%3,y=j-j%3;
        for(int k=0;k<3;k++){
            for(int kk=0;kk<3;kk++){
                if(arr[k+x][kk+y]==val){
                    return false;
                }
            }
        }
        return true;
    }
    bool fun(int x,int y,vector<vector<char>>& board){
        if(x==9){
            return true;
        }
        if(y==9){
            return fun(x+1,0,board);
        }
        if(board[x][y]!='.'){
            return fun(x,y+1,board);
        }
        for(int c='1';c<='9';c++){
            if(valid(board,x,y,c)){
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