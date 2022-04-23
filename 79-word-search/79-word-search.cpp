class Solution {
public:
    bool fun(int x,int y,vector<vector<char>>&board,string word,int d){
        if(d>=word.length()){
            return true;
        }
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || word[d]!=board[x][y]){
            return false;
        }
        char c=board[x][y];
        board[x][y]='.';
        if ((fun(x+1,y,board,word,d+1) || fun(x-1,y,board,word,d+1) || fun(x,y+1,board,word,d+1) || fun(x,y-1,board,word,d+1))){
            return true;
        }
        board[x][y]=c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    v.push_back({i,j});
                }
            }
        }
        for(int i=0;i<v.size();i++){
            if(fun(v[i].first,v[i].second,board,word,0)){
                return true;
            }
        }
        return false;
    }
};