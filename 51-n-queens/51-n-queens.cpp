class Solution {
public:
    vector<vector<string>>ans;
    bool f(int x,int y,vector<string>v){
        int i=x;
        int j=y;
        int n=v.size();
        while(i>=0 && j>=0 && i<n && j<n){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
        }
        i=x;
        j=y;
        while(i>=0 && j>=0 && i<n && j<n){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        i=x;
        j=y;
        while(i>=0 && j>=0 && i<n && j<n){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void fun(int x,vector<string>v,int n){
        if(x==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(f(x,i,v)){
                v[x][i]='Q';
                fun(x+1,v,n);
                v[x][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++){
            s+='.';
        }
        vector<string>v;
        for(int i=0;i<n;i++){
            v.push_back(s);
        }
        fun(0,v,n);
        return ans;
    }
};