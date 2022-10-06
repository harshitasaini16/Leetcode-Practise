class Solution {
public:
    vector<vector<string>>ans;
    bool safe(int x,int y,vector<string>v){
        int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++){
            if(v[i][y]=='Q'){
                return false;
            }
        }
        for(int j=0;j<m;j++){
            if(v[x][j]=='Q'){
                return false;
            }
        }
        int i=x;
        int j=y;
        while(i>=0 && j>=0 && i<n && j<m){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        i=x;
        j=y;
        while(i>=0 && j>=0 && i<n && j<m){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void fun(int x,int n,vector<string>v){
        if(x>=n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(safe(x,i,v)){
                v[x][i]='Q';
                fun(x+1,n,v);
                v[x][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<string>v;
        for(int i=0;i<n;i++){
            string b="";
            for(int j=0;j<n;j++){
                b.push_back('.');
            }
            v.push_back(b);
        }
        fun(0,n,v);
        return ans;
    }
};