class Solution {
public:
    int ans;
    bool issafe(int i,int j,vector<vector<int>>mat,int n){
        for(int x=0;x<n;x++){
            if(mat[x][j]==1){
                return false;
            }
        }
        int x=i,y=j;
        while(x>=0 && y>=0){
            if(mat[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        x=i,y=j;
        while(x<n && y>=0){
            if(mat[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        x=i,y=j;
        while(x>n && y>n){
            if(mat[x][y]==1){
                return false;
            }
            x++;
            y++;
        }
        x=i,y=j;
        while(x>=0 && y<n){
            if(mat[x][y]==1){
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    void fun(int x,int n,vector<vector<int>>mat){
        if(x==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(x,i,mat,n)){
                mat[x][i]=1;
                fun(x+1,n,mat);
                mat[x][i]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        ans=0;
        fun(0,n,mat);
        return ans;
    }
};