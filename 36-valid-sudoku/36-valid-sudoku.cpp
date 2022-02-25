class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<pair<int,char>,int>row;
        map<pair<int,char>,int>col;
        map<pair<int,char>,int>s;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                   row[{i,board[i][j]}]++;
                   col[{j,board[i][j]}]++;
                }
            }
        }
        int p=1;
        int n=9;
        for(int i=0;i<n;i=i+3){
            for(int j=0;j<n;j=j+3){
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y]!='.'){
                            s[{p,board[x][y]}]++;
                        }
                    }
                }
                p++;
            }
        }
        for(auto i:row){
            if(i.second>1){
                return false;
            }
        }
        for(auto i:col){
            if(i.second>1){
                return false;
            }
        }
        for(auto i:s){
            if(i.second>1){
                return false;
            }
        }
        return true;
    }
};