class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        map<pair<int,char>,int>row;
        map<pair<int,char>,int>col;
        map<pair<int,char>,int>box;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    row[{i,board[i][j]}]++;
                    col[{j,board[i][j]}]++;
                }
            }
        }
        int p=1;
        for(int i=0;i<n;i=i+3){
            for(int j=0;j<n;j=j+3){
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y]!='.'){
                            box[{p,board[x][y]}]++;
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
        for(auto i:box){
            if(i.second>1){
                return false;
            }
        }
        return true;
    }
};