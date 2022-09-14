class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    bool fun(int x,int y,int k,vector<vector<char>>&board, string word){
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]!=word[k]){
            return false;
        }
        if(k==word.length()-1){
            return true;
        }
        char c=board[x][y];
        board[x][y]='.';
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(fun(xx,yy,k+1,board,word)){
                return true;
            }
        }
        board[x][y]=c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(fun(i,j,0,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};