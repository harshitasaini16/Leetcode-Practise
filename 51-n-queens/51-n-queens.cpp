class Solution {
public:
    vector<vector<string>>ans;
    bool valid(int x,int y,int n,vector<string>v){
        for(int i=0;i<n;i++){
            if(v[x][i]=='Q'){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            if(v[i][y]=='Q'){
                return false;
            }
        }
        int i=x,j=y;
        while(i>=0 && j>=0){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        i=x,j=y;
        while(i>=0 && j<n){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void fun(int x,int n,vector<string>v){
        if(x==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(valid(x,i,n,v)){
                v[x][i]='Q';
                fun(x+1,n,v);
                v[x][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s.push_back('.');
            }
            v.push_back(s);
        }
        fun(0,n,v);
        return ans;
    }
};