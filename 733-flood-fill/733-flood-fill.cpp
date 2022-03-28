class Solution {
public:
    map<pair<int,int>,int>dp;
    void fun(int x,int y,vector<vector<int>>& image,int oc,int nc,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m || image[x][y]!=oc || dp[{x,y}]!=0){
            return;
        }
        dp[{x,y}]++;
        image[x][y]=nc;
        fun(x+1,y,image,oc,nc,n,m);
        fun(x-1,y,image,oc,nc,n,m);
        fun(x,y+1,image,oc,nc,n,m);
        fun(x,y-1,image,oc,nc,n,m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc) {
        dp.clear();
        int n=image.size();
        int m=image[0].size();
        fun(sr,sc,image,image[sr][sc],nc,n,m);
        return image;
    }
};