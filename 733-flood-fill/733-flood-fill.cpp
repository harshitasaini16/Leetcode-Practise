class Solution {
public:
    void fun(vector<vector<int>>&mat, int x, int y, int n,int m,int col,int nc){
        if(x<0 || y<0 || x>=n || x>=m || mat[x][y]!=col || mat[x][y]==nc){
            return;
        }
        mat[x][y]=nc;
        fun(mat,x+1,y,n,m,col,nc);
        fun(mat,x-1,y,n,m,col,nc);
        fun(mat,x,y+1,n,m,col,nc);
        fun(mat,x,y-1,n,m,col,nc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>&mat, int sr, int sc, int nc) {
        int col=mat[sr][sc];
        int n=mat.size();
        int m=mat[0].size();
        fun(mat,sr,sc,n,m,col,nc);
        return mat;
    }
};