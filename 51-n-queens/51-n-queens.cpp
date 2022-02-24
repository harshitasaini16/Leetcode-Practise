class Solution {
public:
    vector<vector<string>>ans;
    bool issafe(int i,int j,vector<string>mat,int n){
        for(int x=0;x<n;x++){
            if(mat[x][j]=='Q'){
                return false;
            }
        }
        int x=i,y=j;
        while(x>=0 && y>=0){
            if(mat[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }
        x=i,y=j;
        while(x<n && y>=0){
            if(mat[x][y]=='Q'){
                return false;
            }
            x++;
            y--;
        }
        x=i,y=j;
        while(x>n && y>n){
            if(mat[x][y]=='Q'){
                return false;
            }
            x++;
            y++;
        }
        x=i,y=j;
        while(x>=0 && y<n){
            if(mat[x][y]=='Q'){
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    void fun(int x,int n,vector<string>mat){
        if(x==n){
            ans.push_back(mat);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(x,i,mat,n)){
                mat[x][i]='Q';
                fun(x+1,n,mat);
                mat[x][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        string s="";
        for(int i=0;i<n;i++){
            s.push_back('.');
        }
        vector<string>mat(n,s);
        fun(0,n,mat);
        return ans;
    }
};