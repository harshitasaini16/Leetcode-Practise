class Solution {
public:
    bool check(vector<vector<char>>&arr,int i,int j,char c){
        int r=i-i%3,cc=j-j%3;
        for(int k=0;k<9;k++){
            if(arr[k][j]==c or arr[i][k]==c){
                return false;
            }
        }
        for(int k=0;k<3;k++){
            for(int kk=0;kk<3;kk++){
                if(arr[k+r][kk+cc]==c){
                    return false;
                }
            }
        }
        return true;
    }
    bool fun(vector<vector<char>>&arr,int i,int j){
        if(i==9){
            return true;
        }
        if(j==9){
            return fun(arr,i+1,0);
        }
        if(arr[i][j]!='.'){
            return fun(arr,i,j+1);
        }
        for(char c='1' ;c<='9';c++ ){
            if(check(arr,i,j,c)==true){
                arr[i][j]=c;
                if(fun(arr,i,j+1))
                    return true;
                arr[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        fun(board,0,0);
    }
};