class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        int m=9;
        for(int i=0;i<9;i++){
            map<int,int>m;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    m[board[i][j]]++;
                }
            }
            for(auto x:m){
                if(x.second>=2){
                    return false;
                }
            }
        }
        for(int j=0;j<9;j++){
            map<int,int>m;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    m[board[i][j]]++;
                }
            }
            for(auto x:m){
                if(x.second>=2){
                    return false;
                }
            }
        }
        for(int i=0;i<n;i=i+3){
            for(int j=0;j<n;j+=3){
                map<int,int>m;
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                       if(board[x+i][y+j]!='.'){
                            m[board[i+x][j+y]]++;
                       }
                    }
                }
                for(auto x:m){
                    if(x.second>=2){
                      return false;
                    }
                }
            }
        }
        return true;
    }
};