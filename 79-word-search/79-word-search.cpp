class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0};
    bool fun(int x,int y,vector<vector<char>>&board,string s,int k){
        if(k>=s.length()){
            return true;
        }
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]!=s[k]){
            return false;
        }
        char c=board[x][y];
        if(board[x][y]==s[k]){
            board[x][y]='.';
            for(int i=0;i<4;i++){
                if(fun(x+dx[i],y+dy[i],board,s,k+1)){
                    return true;
                }
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
                    if(fun(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};